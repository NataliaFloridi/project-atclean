#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

const int sensorPin = A0;  
const int buzzerPin = D5;  
const int gasThreshold = 500;  

const char* wifiSSID = "UntrustedNetwork";  
const char* wifiPassword = null;  

const char* aioServer = "io.adafruit.com";
const int aioPort = 1883;
const char* aioUsername = "NatFloridi";  
const char* aioKey = null;  

WiFiClient wifiClient;
Adafruit_MQTT_Client mqttClient(&wifiClient, aioServer, aioPort, aioUsername, aioKey);

char gasLevelFeedBuffer[100];
char gasStatusFeedBuffer[100];

Adafruit_MQTT_Publish *gasLevelFeed;
Adafruit_MQTT_Publish *gasStatusFeed;

void connectToWiFi() {
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(wifiSSID, wifiPassword);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi!");
}

void connectToMQTT() {
  while (!mqttClient.connected()) {
    Serial.print("Connecting to Adafruit IO...");
    if (mqttClient.connect()) {
      Serial.println("Connected!");
    } else {
      Serial.print("Failed to connect, retrying in 5 seconds...");
      delay(5000);
    }
  }
}

void initializeFeeds() {
  snprintf(gasLevelFeedBuffer, sizeof(gasLevelFeedBuffer), "%s/feeds/gaslevel", aioUsername);
  snprintf(gasStatusFeedBuffer, sizeof(gasStatusFeedBuffer), "%s/feeds/gasstatus", aioUsername);

  gasLevelFeed = new Adafruit_MQTT_Publish(&mqttClient, gasLevelFeedBuffer);
  gasStatusFeed = new Adafruit_MQTT_Publish(&mqttClient, gasStatusFeedBuffer);
}

int readGasSensor() {
  int gasReadings[20];  
  int sum = 0;

  for (int i = 0; i < 20; i++) {
    gasReadings[i] = analogRead(sensorPin);
    sum += gasReadings[i];
    delay(100); 
  }

  int averageGasLevel = sum / 20;
  return averageGasLevel;
}

void sendGasData(int gasLevel) {
  if (!gasLevelFeed->publish(gasLevel)) {
    Serial.println("Failed to send gas level to Adafruit IO");
  }

  const char* status = (gasLevel > gasThreshold) ? "Nível Alto!" : "Nível Normal";

  if (!gasStatusFeed->publish(status)) {
    Serial.println("Failed to send gas status to Adafruit IO");
  }

  Serial.print("Gas Level = ");
  Serial.print(gasLevel);
  Serial.println(" units");

  Serial.print("Status: ");
  Serial.println(status);

  if (gasLevel > gasThreshold) {
    digitalWrite(buzzerPin, HIGH);  
  } else {
    digitalWrite(buzzerPin, LOW);   
  }
}

void setup() {
  Serial.begin(9600);

  connectToWiFi();
  connectToMQTT();
  initializeFeeds();

  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);  
  digitalWrite(buzzerPin, LOW); 
}

void loop() {
  if (!mqttClient.connected()) {
    connectToMQTT();
  }

  mqttClient.ping();

  int gasLevel = readGasSensor();
  sendGasData(gasLevel);

  delay(5000); 
}
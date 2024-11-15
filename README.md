# Project At Clean  

## Descrição do projeto  
O **Project At Clean** é um sistema de monitoramento de gases inflamáveis voltado para ambientes industriais, utilizando a conectividade da Internet das Coisas (IoT). Ele emprega o sensor **MQ-2** para detectar gases como metano e butano, enviando alertas em tempo real para uma interface online. O objetivo do projeto é proporcionar um monitoramento contínuo e aumentar significativamente a segurança em ambientes industriais, utilizando uma solução prática e acessível.

O sistema integra o sensor MQ-2 a uma placa **ESP8266**, responsável por processar os dados e transmiti-los via protocolo **MQTT** para a plataforma **Adafruit IO**, que serve como dashboard de controle. Em caso de detecção de níveis elevados de gases, um alarme sonoro é acionado e alertas visuais são exibidos na plataforma.

---

## Como executar o projeto  
1. **Montagem do hardware:**  
   - Conecte o sensor MQ-2 à placa ESP8266 usando uma protoboard;  
   - Adicione um buzzer ativo de 5V para o alerta sonoro.  

2. **Configuração do firmware:**  
   - Programe o ESP8266 com o código para capturar dados do sensor e transmiti-los via MQTT;  
   - Configure as credenciais Wi-Fi e os parâmetros do broker MQTT.  

3. **Monitoramento remoto:**  
   - Configure uma dashboard na plataforma Adafruit IO para exibir os níveis de gás em tempo real e emitir alertas;  
   - Programe notificações automáticas para eventos críticos.  

---

## Componentes principais  
- **Sensor MQ-2:** Detecta gases inflamáveis como metano, butano e GLP.  
- **ESP8266 NodeMCU:** Microcontrolador com conectividade Wi-Fi integrada, responsável pela comunicação com o broker MQTT.  
- **Protoboard:** Utilizada para conectar os componentes eletrônicos sem a necessidade de solda.  
- **Buzzer ativo de 5V:** Emissor de som que alerta localmente sobre níveis elevados de gás.  

---

## Comunicação e funcionalidades  
- **Protocolo MQTT:** Gerencia a transmissão dos dados do ESP8266 para o Adafruit IO.  
- **Adafruit IO:** Interface de controle que exibe os dados em gráficos e envia alertas visuais em tempo real.  
- **Protocolo TCP/IP:** Estabelece a comunicação entre a placa ESP8266 e a internet.  

---

## Implementações futuras  
Para evoluir o projeto, pode-se incluir novos sensores para monitorar outros gases, integrar câmeras de segurança ou alarmes remotos e explorar ferramentas de machine learning para análise preditiva dos dados coletados.

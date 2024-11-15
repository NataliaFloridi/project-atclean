# Project At Clean - Sistema de Monitoramento de Gases Inflamáveis com IoT

Este projeto apresenta um sistema de monitoramento de gases inflamáveis voltado para ambientes industriais, utilizando sensores e conectividade de Internet das Coisas (IoT). O sistema detecta gases como metano e butano, enviando alertas em tempo real para uma interface de controle remoto, proporcionando uma solução acessível e eficiente para monitoramento contínuo, aumentando significativamente a segurança em ambientes industriais.

## Funcionalidade e Uso

Este sistema utiliza o sensor MQ-2, um módulo de detecção de gases inflamáveis, que monitora o ambiente e envia os dados para a plataforma online Adafruit IO via MQTT. Em caso de detecção de níveis elevados de gás, um alarme sonoro é acionado para alertar as pessoas próximas e um alerta visual é exibido na dashboard. Esse projeto é ideal para quem busca aumentar a segurança em ambientes industriais de forma prática e acessível.

### Passos para Reproduzir o Projeto

1. **Montagem do Hardware**: Conecte o sensor MQ-2 à placa ESP8266 usando uma protoboard.
2. **Configuração da Conectividade**: Programe o ESP8266 para enviar os dados para a Adafruit IO usando MQTT.
3. **Monitoramento e Alerta**: Configure a dashboard na Adafruit IO para receber dados em tempo real e exibir alertas visuais e sonoros.

## Hardware Utilizado

- **Sensor de Gás MQ-2**: Detecta gases inflamáveis (metano, butano, GLP).
- **Placa ESP8266 NodeMCU V3 ESP-12**: Placa de prototipagem com Wi-Fi integrado, essencial para comunicação com a internet.
- **Protoboard**: Utilizada para conectar componentes eletrônicos sem necessidade de solda.
- **Buzzer Ativo 5V**: Emissor de som que serve como alarme sonoro local quando há detecção de gás.

## Documentação das Interfaces, Protocolos e Módulos de Comunicação

- **Protocolo MQTT (Message Queuing Telemetry Transport)**: Utilizado para a comunicação entre o ESP8266 e a plataforma de monitoramento Adafruit IO.
- **Protocolo TCP/IP**: Habilita o acesso à internet para transmissão de dados em tempo real.

As interfaces com o Adafruit IO são configuradas para exibir dados dos sensores e gerar alertas de forma visual e intuitiva. A transmissão dos dados é realizada pelo ESP8266, que se conecta ao MQTT broker na plataforma Adafruit IO, transmitindo informações sobre os níveis de gás.

## Comunicação e Controle via Internet

O projeto emprega o protocolo MQTT para monitoramento remoto, permitindo:

1. **Envio de dados em tempo real**: Os níveis de gás são monitorados continuamente e enviados para a dashboard online.
2. **Controle remoto**: Com o acesso ao painel na Adafruit IO, é possível acompanhar a situação em tempo real e receber alertas de forma rápida e eficiente.


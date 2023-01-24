#include "PinsDefinition.h"


void setup() {
  /*Inicia la interfaz de hardware serie 2 con 9600 baudios y 8 bits 
  sin paridad más 1 bit de parada en los pines GPIO3(RX) y GPIO1 (TX)*/
  Serial.begin(9600, SERIAL_8N1, R0, DI);  // RX=3 , TX =1
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);

  // poner RS-485 en modo de recepción
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);

  connectAWS();
}

void loop() {
  delay(1000);
  sendSoilValuesInIntervals();
  keepMqttConnection();
} 
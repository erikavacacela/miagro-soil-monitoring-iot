#include "PinsDefinition.h"


class ResistiveSoilMoistureSensor {

  const char sensorType[10]="RESISTIVE";
  const int AIR_VALUE = 4095;
  const int WATER_VALUE = 2400;

  public:

    int readSoilMoisture() {
      // Se lee la conductividad entre valores 4095 y 370
      int soilRead = analogRead(RESISTIVE_SOIL_MOISTURE_PIN);
      Serial.print("Resistive soil moisture: ");
      Serial.print(soilRead);
      // Mapeamos el valor para pasarlo a porcentaje
      // Si el valor es cercano a 100 hay mayor humedad
      int mapValue = round(map(soilRead, AIR_VALUE, WATER_VALUE, 0, 100));
      Serial.print(" - ");
      Serial.print(mapValue);
      Serial.println("%");
      Serial.println("--------------------------------");
      return mapValue;
    }

    void publishValue() {
      int soilMoisture = readSoilMoisture();

      char jsonBuffer[512];
      StaticJsonDocument<200> doc;
      doc["time"] = millis();
      doc["sensor_type"] = sensorType;
      doc["humidity"] = soilMoisture;
      serializeJson(doc, jsonBuffer);

      publishMessage(jsonBuffer);
    }

};
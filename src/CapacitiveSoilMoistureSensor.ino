#include "PinsDefinition.h"

class CapacitiveSoilMoistureSensor {

  const char sensorType[11]="CAPACITIVE";
  const int AIR_VALUE = 2900;
  const int WATER_VALUE = 1400;

  public:

    int readSoilMoisture() {
      int soilRead = analogRead(CAPACITIVE_SOIL_MOISTURE_PIN);
      Serial.print("Capacitive soil moisture: ");
      Serial.print(soilRead);
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
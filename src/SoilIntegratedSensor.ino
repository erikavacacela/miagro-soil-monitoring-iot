
/*Matriz para obtener los datos del sensor 
Direccion del codigo, funcion del codigo, 
registrar direccion desde inicio, longitud deregistro
CRC_L, CRC_H
Estos valores se toma como refeencia de la hoja de datos NPK*/

// Values from manual
const byte temp_hum[] = {0x01, 0x03, 0x00, 0x12, 0x00, 0x02, 0x65, 0xCB};
// const byte nitro[] = {0x01, 0x03, 0x00, 0x1e, 0x00, 0x01, 0xB5, 0xCC};
// const byte phos[] = {0x01, 0x03, 0x00, 0x1f, 0x00, 0x01, 0xE4, 0x0C};
// const byte pota[] = {0x01, 0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xC0};
// const byte ph[] = {0x01, 0x03, 0x00, 0x06, 0x00, 0x01, 0x64, 0x0B};
const byte moisture[] = {0x01, 0x03, 0x00, 0x12, 0x00, 0x01, 0x25, 0xCA};
const byte npk[] = {0x01, 0x03, 0x00, 0x1E, 0x00, 0x03, 0x34, 0x0D};

// Values from program
const byte nitro[] = {0x01, 0x03, 0x00, 0x1E, 0x00, 0x01, 0xE4, 0x0C};
const byte phos[] = {0x01, 0x03, 0x00, 0x1F, 0x00, 0x01, 0xB5, 0xCC};
const byte pota[] = {0x01, 0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xC0};
const byte humidity[] = {0x01, 0x03, 0x00, 0x12, 0x00, 0x01, 0x24, 0x0F};
const byte temperature[] = {0x01, 0x03, 0x00, 0x13, 0x00, 0x01, 0x75, 0xCF};
const byte ph[] = {0x01, 0x03, 0x00, 0x06, 0x00, 0x01, 0x64, 0x0B};


byte values [11];

struct IntegratedSensorVars
{
  byte nitrogen;
  byte phosphorous;
  byte potassium;
  byte soilMoisture;
  byte ph;
  byte temperature;
  byte humidity;
};

IntegratedSensorVars integratedSensorVars;

class SoilIntegratedSensor {

  const char sensorType[11]="INTEGRATED";

  public:

    byte readNitrogen(){
      /*esto eliminaba los datos en serie entrantes almacenados en el búfer*/
      Serial.flush();  
      // cambiar RS-485 al modo de transmisión
      digitalWrite(DE, HIGH);
      digitalWrite(RE, HIGH);
      delay(1000);
      //Escribir el mensaje 
      for (uint8_t i = 0; i < sizeof(nitro); i++ ) Serial.write( nitro[i] );
      Serial.flush();
      // cambiando RS485 al modo de recepción  
      digitalWrite(DE, LOW);
      digitalWrite(RE, LOW);
      // tiempo para permitir que se reciban los bytes de respuesta!
      delay(1000);
      // leer los bytes recibidos
      for (byte i = 0; i < 7; i++) {
        values[i] = Serial.read();
        Serial.print(values[i], HEX);
        Serial.print(' ');
      }
      return values[4];
    }

    byte readPhosphorous() {
      Serial.flush();
      digitalWrite(DE, HIGH);
      digitalWrite(RE, HIGH);
      delay(1000);
      for (uint8_t i = 0; i < sizeof(phos); i++ ) Serial.write( phos[i] );
      Serial.flush();
      digitalWrite(DE, LOW);
      digitalWrite(RE, LOW);
      delay(1000);
      for (byte i = 0; i < 7; i++) {
        values[i] = Serial.read();
        Serial.print(values[i], HEX);
        Serial.print(' ');
      }
      return values[4];
    }

    byte readPotassium() {
      Serial.flush();
      digitalWrite(DE, HIGH);
      digitalWrite(RE, HIGH);
      delay(1000);
      for (uint8_t i = 0; i < sizeof(pota); i++ ) Serial.write( pota[i] );
      Serial.flush();
      digitalWrite(DE, LOW);
      digitalWrite(RE, LOW);
      delay(1000);
      for (byte i = 0; i < 7; i++) {
        values[i] = Serial.read();
        Serial.print(values[i], HEX);
        Serial.print(' ');
      }
      return values[4];
    }

    byte readHumidity() {
      Serial.flush();
      digitalWrite(DE, HIGH);
      digitalWrite(RE, HIGH);
      delay(1000);
      for (uint8_t i = 0; i < sizeof(humidity); i++ ) Serial.write( humidity[i] );
      Serial.flush();
      digitalWrite(DE, LOW);
      digitalWrite(RE, LOW);
      delay(1000);
      for (byte i = 0; i < 7; i++) {
        values[i] = Serial.read();
        Serial.print(values[i], HEX);
        Serial.print(' ');
      }
      return values[4];
    }

    byte readTemperature() {
      Serial.flush();
      digitalWrite(DE, HIGH);
      digitalWrite(RE, HIGH);
      delay(1000);
      for (uint8_t i = 0; i < sizeof(temperature); i++ ) Serial.write( temperature[i] );
      Serial.flush();
      digitalWrite(DE, LOW);
      digitalWrite(RE, LOW);
      delay(1000);
      for (byte i = 0; i < 7; i++) {
        values[i] = Serial.read();
        Serial.print(values[i], HEX);
        Serial.print(' ');
      }
      return values[4];
    }

    byte readSoilMoisture() {
      Serial.flush();
      digitalWrite(DE, HIGH);
      digitalWrite(RE, HIGH);
      delay(1000);
      for (uint8_t i = 0; i < sizeof(moisture); i++ ) Serial.write( moisture[i] );
      Serial.flush();
      digitalWrite(DE, LOW);
      digitalWrite(RE, LOW);
      delay(1000);
      for (byte i = 0; i < 7; i++) {
        values[i] = Serial.read();
        Serial.print(values[i], HEX);
        Serial.print(' ');
      }
      return values[4];
    }

    byte readPh() {
      Serial.flush();
      digitalWrite(DE, HIGH);
      digitalWrite(RE, HIGH);
      delay(1000);
      for (uint8_t i = 0; i < sizeof(ph); i++ ) Serial.write( ph[i] );
      Serial.flush();
      digitalWrite(DE, LOW);
      digitalWrite(RE, LOW);
      delay(1000);
      for (byte i = 0; i < 7; i++) {
        values[i] = Serial.read();
        Serial.print(values[i], HEX);
        Serial.print(' ');
      }
      return values[4];
    }

    void readNPK() {
      Serial.print("NPK: ");

      Serial.flush();
      digitalWrite(DE, HIGH);
      digitalWrite(RE, HIGH);
      delay(1000);
      for (uint8_t i = 0; i < sizeof(npk); i++ ) Serial.write( npk[i] );
      Serial.flush();
      digitalWrite(DE, LOW);
      digitalWrite(RE, LOW);
      delay(1000);
      for (byte i = 0; i < 11; i++) {
        values[i] = Serial.read();
        Serial.print(values[i], HEX);
        Serial.print(' ');
      }

      // integratedSensorVars.nitrogen = values[4];
      // integratedSensorVars.phosphorous = values[6];
      // integratedSensorVars.potassium = values[8];
      Serial.print(" = ");
      Serial.print(values[4]);
      // Serial.print(integratedSensorVars.nitrogen);
      Serial.print(" - ");
      Serial.print(values[6]);
      // Serial.print(integratedSensorVars.phosphorous);
      Serial.print(" - ");
      Serial.print(values[8]);
      // Serial.print(integratedSensorVars.potassium);
      Serial.println(" mg/kg");
    }

    void readSoilHumidityTemperature() {
      Serial.print("Soil humidity and temperature: ");

      Serial.flush();
      digitalWrite(DE, HIGH);
      digitalWrite(RE, HIGH);
      delay(1000);
      for (uint8_t i = 0; i < sizeof(temp_hum); i++ ) Serial.write( temp_hum[i] );
      Serial.flush();
      digitalWrite(DE, LOW);
      digitalWrite(RE, LOW);
      delay(1000);
      for (byte i = 0; i < 9; i++) {
        values[i] = Serial.read();
        Serial.print(values[i], HEX);
        Serial.print(' ');
      }

      integratedSensorVars.humidity = values[4];
      integratedSensorVars.temperature = values[6];
      Serial.print(" = ");
      Serial.print(integratedSensorVars.humidity);
      Serial.print(" - ");
      Serial.print(integratedSensorVars.temperature);
      Serial.println("");
    }

    void readIntegratedValues() {
      Serial.print("Nitrogeno: ");
      integratedSensorVars.nitrogen = readNitrogen();
      Serial.print(" = ");
      Serial.print(integratedSensorVars.nitrogen);
      Serial.println(" mg/kg");

      keepMqttConnection();

      Serial.print("Fosforo: ");
      integratedSensorVars.phosphorous = readPhosphorous();
      Serial.print(" = ");
      Serial.print(integratedSensorVars.phosphorous);
      Serial.println(" mg/kg");

      keepMqttConnection();

      Serial.print("Potasio: ");
      integratedSensorVars.potassium = readPotassium();
      Serial.print(" = ");
      Serial.print(integratedSensorVars.potassium);
      Serial.println(" mg/kg");

      keepMqttConnection();

      Serial.print("Humidity: ");
      integratedSensorVars.humidity = readHumidity() * 0.1;
      Serial.print(" = ");
      Serial.print(integratedSensorVars.humidity);
      Serial.println(" RH");

      keepMqttConnection();

      Serial.print("Temperature: ");
      integratedSensorVars.temperature = readTemperature() * 0.1;
      Serial.print(" = ");
      Serial.print(integratedSensorVars.temperature);
      Serial.println(" *C");

      keepMqttConnection();

      Serial.print("PH: ");
      integratedSensorVars.ph = readPh() * 0.01;
      Serial.print(" = ");
      Serial.print(integratedSensorVars.ph);
      Serial.println(" PH");

      keepMqttConnection();

      // Serial.print("Moisture: ");
      // integratedSensorVars.soilMoisture = readSoilMoisture();
      // Serial.print(" = ");
      // Serial.print(integratedSensorVars.soilMoisture);
      // Serial.println(" RH");



      // keepMqttConnection();

      readNPK();

      keepMqttConnection();

      // readSoilHumidityTemperature();

      // keepMqttConnection();
    }

    void publishValue() {
      readIntegratedValues();

      char jsonBuffer[512];
      StaticJsonDocument<200> doc;
      doc["time"] = millis();
      doc["sensor_type"] = sensorType;
      doc["nitrogen"] = integratedSensorVars.nitrogen;
      doc["phosphorous"] = integratedSensorVars.phosphorous;
      doc["potassium"] = integratedSensorVars.potassium;
      // doc["soilMoisture"] = integratedSensorVars.soilMoisture;
      doc["ph"] = integratedSensorVars.ph;
      doc["temperature"] = integratedSensorVars.temperature;
      doc["humidity"] = integratedSensorVars.humidity;
      serializeJson(doc, jsonBuffer);

      publishMessage(jsonBuffer);
    }

};





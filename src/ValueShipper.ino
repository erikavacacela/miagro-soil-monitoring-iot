
ResistiveSoilMoistureSensor resistiveSoilMoistureSensor;
CapacitiveSoilMoistureSensor capacitiveSoilMoistureSensor;
SoilIntegratedSensor soilIntegratedSensor;

unsigned long lastSendTimeResistive, lastSendTimeCapacitive, lastSendTimeIntegrated, currentMillis;
const unsigned long intervalThreeMin = 2UL*60UL*1000UL;   // Example: 12UL*60UL*60UL*1000U every 12 hours
const unsigned long intervalOneMin = 1UL*60UL*1000UL;   // 1UL*60UL*1000U every 1 minute

void sendSoilValuesInIntervals() {

  currentMillis = millis(); // update with every loop

  // Sent data for resistive sensor
  if (currentMillis - lastSendTimeResistive >= intervalOneMin){
    lastSendTimeResistive = currentMillis; // new startpoint

    resistiveSoilMoistureSensor.publishValue();    
  }

  // Sent data for capacitive sensor
  if (currentMillis - lastSendTimeCapacitive >= intervalOneMin){
    lastSendTimeCapacitive = currentMillis; // new startpoint

    capacitiveSoilMoistureSensor.publishValue();    
  }

  // Sent data for capacitive sensor
  if (currentMillis - lastSendTimeIntegrated >= intervalThreeMin){
    lastSendTimeIntegrated = currentMillis; // new startpoint

    soilIntegratedSensor.publishValue();    
  }
  
}

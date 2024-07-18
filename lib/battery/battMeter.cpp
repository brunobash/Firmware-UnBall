#include <battMeter.hpp>

void setup()
{
  //pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  int sensorValue = analogRead(A0);
  
  // Calculo do tensão da bateria
  float voltage = sensorValue * (3.3 / 1023.0) * ((R1+R2) / R2);
  
 
  Serial.print("Tensão: ");
  Serial.print(voltage);
  Serial.println(" V");	
  
  
  // Calculo de porcentagem nível de carga
  float batteryLevel = (voltage - VOLTAGE_MIN) / (VOLTAGE_MAX - VOLTAGE_MIN) * 100;
  batteryLevel = constrain(batteryLevel, 0, 100);
  
  
  Serial.print("Battery Level: ");
  Serial.print(batteryLevel);
  Serial.println(" %");
  
  // delay(1000);

}

/*
problema de permissao é só dar um chmod 777 /dev/ttyUSB0
*/
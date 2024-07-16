#define BATTERY_PIN A0
#define R1 100000.00
#define R2 56000.00
#define VOLTAGE_MAX 8.4
#define VOLTAGE_MIN 7.4
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

void setup()
{
  //pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(BATTERY_PIN);
  
  // Calculo do tensão da bateria
  float voltage = sensorValue * (5.0 / 1023.0) * ((R1+R2) / R2);
  
 
  Serial.print("Tensão: ");
  Serial.print(voltage);
  Serial.println(" V");	
  
  
  // Calculo de porcentagem nível de carga
  float batteryLevel = (voltage - VOLTAGE_MIN) / (VOLTAGE_MAX - VOLTAGE_MIN) * 100;
  batteryLevel = constrain(batteryLevel, 0, 100);
  
  
  Serial.print("Battery Level: ");
  Serial.print(batteryLevel);
  Serial.println(" %");
  
  delay(1000);

}
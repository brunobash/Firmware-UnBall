#ifndef BATTMETER_HPP
#define BATTMETER_HPP

#define R1 25000.00
#define R2 14800.00
#define VOLTAGE_MAX 8.4
#define VOLTAGE_MIN 7.4
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

namespace BattMeter {
    void setup(void);
}


#endif
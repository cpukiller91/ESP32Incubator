
//========================================================
//ESP32 Web Server: Reading Potentiometer Value using AJAX
//========================================================
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "webpage.h"

//---------------------------------------------------

#include <ESP32Servo.h>
Servo servo1;
// Published values for SG90 servos; adjust if needed
int minUs = 1000;
int maxUs = 2000;
#if defined(ARDUINO_ESP32S2_DEV)
int servo1Pin = 13;
#else
int servo1Pin = 32;
#endif
int Heating = 23;
int PUMP = 18;
int ventelation = 6;
int curculation = 7;
int pos = 0;      // position in degrees
ESP32PWM pwm;
//---------------------------------------------------

#include <Wire.h>
#include "DFRobot_SHT20.h"
DFRobot_SHT20 sht20;

//---------------------------------------------------
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
// Number of temperature devices found
int numberOfDevices;
bool pumpStatus = LOW;
bool HeatingStatus = HIGH;

// We'll use this variable to store a found device address
DeviceAddress tempDeviceAddress; 
//---------------------------------------------------
WebServer server(80);
const char* ssid = "TOTOLINK_N300RT";
const char* password = "77700011";

//---------------------------------------------------
#include "handleFunctions.h"
//===================================================
// function to print a device address
void printAddress(DeviceAddress deviceAddress) {
  for (uint8_t i = 0; i < 8; i++){
    if (deviceAddress[i] < 16) Serial.print("0");
      Serial.print(deviceAddress[i], HEX);
  }
}
void setup()
{
  
  //-------------------------------------------------
  ESP32PWM::allocateTimer(0);
  //-------------------------------------------------
  Serial.begin(115200);
  servo1.setPeriodHertz(50);      // Standard 50hz servo
  //-------------------------------------------------
  
  // Start up the library
  sensors.begin();
  
  // Grab a count of devices on the wire
  numberOfDevices = sensors.getDeviceCount();
  
  // locate devices on the bus
  Serial.print("Locating devices...");
  Serial.print("Found ");
  Serial.print(numberOfDevices, DEC);
  Serial.println(" devices.");

  // Loop through each device, print out address
  for(int i=0;i<numberOfDevices; i++){
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i)){
      Serial.print("Found device ");
      Serial.print(i, DEC);
      Serial.print(" with address: ");
      printAddress(tempDeviceAddress);
      Serial.println();
    } else {
      Serial.print("Found ghost device at ");
      Serial.print(i, DEC);
      Serial.print(" but could not detect address. Check power and cabling");
    }
  }

  //-------------------------------------------------
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while(WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    delay(500); Serial.print(".");
  }
   //-------------------------------------------------
  if (MDNS.begin("inkubator")) {
    Serial.println("MDNS responder started");
  }
  //-------------------------------------------------
  Serial.println("SHT20 Example!");
  sht20.initSHT20(); // Init SHT20 Sensor
  delay(100);
  sht20.checkSHT20(); // Check SHT20 Sensor
  //-------------------------------------------------
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  //-------------------------------------------------
  server.on("/", handleRoot);
//  server.on("/getTemp", handlePOT);

  server.on("/getHumd", getHumd);
  
  server.on("/getTempTop", getTempTop);
  server.on("/getTempLeft", getLeftTemperature);
  server.on("/getTempCenter", getCenterTemperature);
  server.on("/getTempRight", getRightTemperature);
  server.on("/getTempHeater", getTempHeater);
  
  server.on("/startHeating", startHeating);
  server.on("/stopHeating", stopHeating);
  
  server.on("/startPump", startPump);
  server.on("/stopPump", stopPump);
  server.on("/getWaterLevel", getWaterLevel);
  
  server.on("/startVentilation", startVentilation);
  server.on("/stopVentilation", stopVentilation);
  
  
  server.begin();
  Serial.println("HTTP server started");

  pinMode(Heating, OUTPUT);
  pinMode(PUMP, OUTPUT);
  digitalWrite(PUMP, pumpStatus);
  digitalWrite(Heating, HeatingStatus);
}
//===================================================
void loop(void)
{
  sensors.requestTemperatures(); // Send the command to get temperatures
  

//  servo1.attach(servo1Pin, minUs, maxUs);
//  for (pos = 0; pos <= 180; pos += 1) { // sweep from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    servo1.write(pos);
//    delay(1);             // waits 20ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 1) { // sweep from 180 degrees to 0 degrees
//    servo1.write(pos);
//    delay(1);
//  }
  server.handleClient(); delay(1);
}

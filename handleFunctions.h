//=============================================
//Handle functions executed upon client request
//=============================================
void handleRoot()
{
 server.send(200, "text/html", webpageCode);
}
//---------------------------------------
void handlePOT()
{
 String POTval = String(analogRead(A0));
 server.send(200, "text/plane", POTval);
}
//---------------------------------------
void getLeftTemperature()
{
  String temp = "";
  if(sensors.getAddress(tempDeviceAddress, 1)){
    
      temp = String(sensors.getTempC(tempDeviceAddress)); // Read Temperature
  }
 server.send(200, "text/plane", temp);
}
//---------------------------------------
void getTempHeater()
{
  String temp = "";
  
  temp = String(analogRead(32));
 server.send(200, "text/plane", temp);
}
//---------------------------------------
void getRightTemperature()
{
  String temp = "";
  if(sensors.getAddress(tempDeviceAddress, 0)){
    
      temp = String(sensors.getTempC(tempDeviceAddress)); // Read Temperature
     
    }
//  
// float temp = sht20.readTemperature(); // Read Temperature
// String HumdTemp = String(analogRead(A0));
 server.send(200, "text/plane", temp);
}
//---------------------------------------
void getCenterTemperature()
{
  String temp = "";
  if(sensors.getAddress(tempDeviceAddress, 2)){
    
      temp = String(sensors.getTempC(tempDeviceAddress)); // Read Temperature
     
    }
 server.send(200, "text/plane", temp);
}
//---------------------------------------
void getHumd()
{
 String humd = String(sht20.readHumidity()); // Read Humidity
// float temp = sht20.readTemperature(); // Read Temperature
// String HumdTemp = String(analogRead(A0));
 server.send(200, "text/plane", humd);
}
void getTempTop()
{
 String Temp = String(sht20.readTemperature()); // Read Humidity
// float temp = sht20.readTemperature(); // Read Temperature
// String HumdTemp = String(analogRead(A0));
 server.send(200, "text/plane", Temp);
}

void startHeating()
{
 HeatingStatus = LOW;
 digitalWrite(Heating, HeatingStatus);
 server.send(200, "text/plane", "1");
}

void stopHeating()
{
 HeatingStatus = HIGH;
 digitalWrite(Heating, HeatingStatus);
 server.send(200, "text/plane", "0");
}

void startPump()
{
 pumpStatus = HIGH;
 digitalWrite(PUMP, pumpStatus);
 server.send(200, "text/plane", "1");
}

void stopPump()
{
 pumpStatus = LOW;
 digitalWrite(PUMP, pumpStatus);
 server.send(200, "text/plane", "0");
}

void getWaterLevel()
{
// String Temp = String(sht20.readTemperature()); // Read Humidity
// float temp = sht20.readTemperature(); // Read Temperature
// String HumdTemp = String(analogRead(A0));
 server.send(200, "text/plane", "0");
}

void startVentilation()
{
// String Temp = String(sht20.readTemperature()); // Read Humidity
// float temp = sht20.readTemperature(); // Read Temperature
// String HumdTemp = String(analogRead(A0));
 server.send(200, "text/plane", "0");
}

void stopVentilation()
{
// String Temp = String(sht20.readTemperature()); // Read Humidity
// float temp = sht20.readTemperature(); // Read Temperature
// String HumdTemp = String(analogRead(A0));
 server.send(200, "text/plane", "0");
}

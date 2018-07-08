#include <PTCaptivePortal.h>
#include <ESP8266Ping.h> // biblioteca -> https://github.com/dancol90/ESP8266Ping

// Doing Something
// by Nuno Azevedo <https://www.nunoazev.com>
// Created 8 jul 2018

PTCaptivePortal captive;

void setup()
{
   Serial.begin(115200);
   delay(10);
   captive.NosConnect("user","pass");
}

void loop()
{
     Serial.print("Pinging host ");

  if (Ping.ping("www.google.com")) {
    Serial.println("Success!!");
  } else {
    Serial.println("Error :(");
  }

  
  delay(500);
}


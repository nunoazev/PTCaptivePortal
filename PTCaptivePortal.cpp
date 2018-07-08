/*
 PtCaptive.h - Library for Login in portuguese Captive portals - description
 Copyright (c) 2018 Nuno Azevedo.  All right reserved.
 */

// include this library's description file
#include "PTCaptivePortal.h"

// include description files for other libraries used (if any)
#include <ESP8266HTTPClient.h>

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

PTCaptivePortal::PTCaptivePortal()
{
  // initialize this instance's variables
  
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

void PTCaptivePortal::MeoConnect(const char* username, const char* password){
  const String MEOUSR  = username;
  const String MEOPASS  = password;
  const String fingerprint  = "50:FE:E2:67:16:26:3C:D0:64:8F:23:43:5D:B2:82:56:A4:5F:03:B0";

   HTTPClient http;
   http.begin("https://servicoswifi.apps.meo.pt/HotspotConnection.asmx/Login?username=" + MEOUSR+ "&password=" + MEOPASS + "&navigatorLang=pt&callback=foo",fingerprint);
   http.addHeader("Content-Type", "application/javascript; charset=utf-8");
   String payload = http.getString();
   Serial.println(payload);
   http.end();
  
}

void PTCaptivePortal::NosConnect(const char* username, const char* password){

    //nos login captive
    const String NOSUSR  = username;
    const String NOSPASS  = password;
    //gerada aqui -> https://www.grc.com/fingerprints.htm
    const String fingerprint  = "65:81:07:BF:EE:0D:C9:45:89:C5:2B:5B:DC:02:94:0E:FD:4B:5A:E7";

    String uri = "";
    static const char* LOCATION = "Location";
    static const char* SET_COOKIE = "Set-Cookie";
    static const char* HEADER_NAMES[] = {LOCATION, SET_COOKIE};

    HTTPClient http;
    http.begin("http://captive.apple.com/");
    http.collectHeaders(HEADER_NAMES, 2);
    int httpCode = http.GET();
    uri = http.header(LOCATION);
    delay(2000);

    http.begin(uri,fingerprint);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    http.addHeader("Cookie", http.header(SET_COOKIE));
    httpCode = http.POST("userFake=" + NOSUSR + "&UserName=NOS/" + NOSUSR + "&Password=" + NOSPASS);
    delay(2000);


    uri = http.header(LOCATION);
    http.collectHeaders(HEADER_NAMES, 2);
    httpCode = http.GET();
    http.begin(uri);
    delay(2000);


    uri = http.header(LOCATION);
    http.collectHeaders(HEADER_NAMES, 2);
    httpCode = http.GET();
    http.begin(uri);
    delay(2000);

    
    http.end();  //Close connection


    delay(2000);

    
}



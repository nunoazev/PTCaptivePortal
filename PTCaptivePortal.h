/*
  PtCaptive.h - Library for Login in portuguese Captive portals - description
  Copyright (c) 2018 Nuno Azevedo.  All right reserved.
*/

// ensure this library description is only included once
#ifndef PTCaptivePortal_h
#define PTCaptivePortal_h


// library interface description
class PTCaptivePortal
{
  // user-accessible "public" interface
  public:
    PTCaptivePortal();
    //connect
    void CheckConn();
    void MeoConnect(const char* username, const char* password);
    void NosConnect(const char* username, const char* password);
    

   
};

#endif


#include <hidboot.h>
#include <usbhub.h>

#include "KeyboardParser.h"
#include <Keyboard.h>

USB     Usb;
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);
KeyboardParser Prs;

void setup() {
  Usb.Init();
    
  HidKeyboard.SetReportParser(0, &Prs);
  Keyboard.begin();
}

void loop()
{  
  Usb.Task();
}


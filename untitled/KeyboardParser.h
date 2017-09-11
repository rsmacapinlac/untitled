// ensure this library description is only included once
#ifndef KeyboardParser_h
#define KeyboardParser_h

#include <Keyboard.h>
#include <hidboot.h>

#include "Templates.h"

class KeyboardParser : public KeyboardReportParser
{
  private:
    bool modifier_keys[8] = { false,false,false,false,false,false,false,false };
    bool modifier_trap = false;
    Templates _template;
    
  protected:
    uint8_t KeyboardParser::ControlKeyState(uint8_t before, uint8_t after);
    uint8_t KeyboardParser::WhatKeyWasPressed(uint8_t mod, uint8_t key);
    String KeyboardParser::GetTemplate(char key);
    bool KeyboardParser::isTriggered(uint8_t key);
    
    void OnControlKeysChanged(uint8_t before, uint8_t after);
    void UpdateControlKeySwitch(uint8_t modifier_key, uint8_t keyboard_modifier);     

    void OnKeyDown  (uint8_t mod, uint8_t key);
    void OnKeyUp  (uint8_t mod, uint8_t key);
};

#endif

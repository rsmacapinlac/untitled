#include "KeyboardParser.h"

#include <Keyboard.h>

void KeyboardParser::UpdateControlKeySwitch(uint8_t modifier_key_index, uint8_t keyboard_modifier) {
  
  if (modifier_keys[modifier_key_index] == false) {
    Keyboard.press(keyboard_modifier);
    modifier_keys[modifier_key_index] = true;
  } else {
    Keyboard.release(keyboard_modifier);
    modifier_keys[modifier_key_index] = false;
  }

}

void KeyboardParser::OnControlKeysChanged(uint8_t before, uint8_t after) {

  MODIFIERKEYS beforeMod;
  *((uint8_t*)&beforeMod) = before;

  MODIFIERKEYS afterMod;
  *((uint8_t*)&afterMod) = after;

  if (beforeMod.bmLeftCtrl != afterMod.bmLeftCtrl) {
    UpdateControlKeySwitch(0, KEY_LEFT_CTRL);
  }
  if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
    UpdateControlKeySwitch(1, KEY_LEFT_SHIFT);
  }
  if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
    UpdateControlKeySwitch(2, KEY_LEFT_ALT);
  }
  if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
    UpdateControlKeySwitch(3, KEY_LEFT_GUI);
  }
  if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
    UpdateControlKeySwitch(4, KEY_RIGHT_CTRL);
  }
  if (beforeMod.bmRightShift != afterMod.bmRightShift) {
    UpdateControlKeySwitch(5, KEY_RIGHT_SHIFT);
  }
  if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
    UpdateControlKeySwitch(6, KEY_RIGHT_ALT);
  }
  if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
    UpdateControlKeySwitch(7, KEY_RIGHT_GUI);
  }
 
}

uint8_t KeyboardParser::WhatKeyWasPressed(uint8_t mod, uint8_t key) {
  uint8_t c = OemToAscii(mod, key);
  uint8_t key_press = c;

  if ((key >= 58) && (key <= 69)) {
    // 194 - 205
    key_press = 194 + (key - 58);
  } else {
    switch(key) {
      case 40:
        key_press = KEY_RETURN;
        break;
      case 41:
        key_press = KEY_ESC;
        break;
      case 42:
        key_press = KEY_BACKSPACE;
        break;
      case 43:
        key_press = KEY_TAB;
        break;
      case 57:
        key_press = KEY_CAPS_LOCK;
        break;
      case 74:
        key_press = KEY_HOME;
        break;
      case 75:
        key_press = KEY_PAGE_UP;
        break;
      case 76:
        key_press = KEY_DELETE;
        break;
      case 77:
        key_press = KEY_END;
        break;
      case 78:
        key_press = KEY_PAGE_DOWN;
        break;
      case 79:
        key_press = KEY_RIGHT_ARROW;
        break;
      case 80:
        key_press = KEY_LEFT_ARROW;
        break;
      case 81:
        key_press = KEY_DOWN_ARROW;
        break;
      case 82:
        key_press = KEY_UP_ARROW;
        break;
    }
  }  
  return key_press;
} 

bool KeyboardParser::isTriggered(uint8_t key_press) {
  bool _triggered = false;
  if (((modifier_keys[0] == 1) || (modifier_keys[4] == 1)) && ((modifier_keys[2] == 1) || (modifier_keys[6] == 1)) && ((key_press >= 48) && (key_press <= 57))) {
    _triggered = true;
  }
  return _triggered;
}

void KeyboardParser::OnKeyUp(uint8_t mod, uint8_t key) {
  uint8_t _key_press = WhatKeyWasPressed(mod, key);
  bool triggered = isTriggered(_key_press);

  if (triggered) {
    int index = int((char)_key_press) - 48;
    // String _data = template_data[index];
    Keyboard.releaseAll();
    String _payload = _template.data[index];
    Keyboard.press(KEY_BACKSPACE); Keyboard.release(KEY_BACKSPACE);
    Keyboard.print(_payload);
  } else {
    Keyboard.release(_key_press);  
  }
}

void KeyboardParser::OnKeyDown(uint8_t mod, uint8_t key) {
  uint8_t _key_press = WhatKeyWasPressed(mod, key);
  Keyboard.press(_key_press);
}

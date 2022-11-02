#include "HomeSpan.h"
//#include "IRremoteESP8266.h"
#include "IRsend.h"

/** Keys suppported by device*/
enum REMOTES_KEY {
  POWER_K,
  INC_LIGHT_K,
  DEC_LIGHT_K,
  RED_K,
  GREEN_K,
  BLUE_K,
  WHITE_K,
  SOFT_ORANGE_K,
  MINT_K,
  VIOLET_K,
  SOFT_LIGHT_K,
  COLGATE_K,
  LIGHT_UV_K,
  NUCLEAR_K,
  UV_K,

  NUM_K
};

// Codes for ir transmitter
uint32_t REMOTE_KEY_CODES[NUM_K] = {
  0xf302fd,  // power
  0xf33ac5,  // increase light
  0xf3ba45,  // decrease light
  0xf31ae5,  // red
  0xf39a65,  // green
  0xf3a25d,  // blue
  0xf322dd,  // white
  0xf32ad5,  // soft orange
  0xf3aa55,  // mint
  0xf3926d,  // violet
  0xf30af5,  // soft light
  0xf39867,  // colgate
  0xf37887,  // light uv
  0xf318e7,  // nuclear
  0xf358a7   // uv
};

// struct holds data for ir transmitter
struct IR_TRANSMITTER : Service::LightBulb {
  REMOTES_KEY keyPressed;
  SpanCharacteristic *code;

  IR_TRANSMITTER(REMOTES_KEY keyDesired)
    : Service::LightBulb() {
    this->keyPressed = keyDesired;
    code = new Characteristic::On();
  }

  // Overload the function so we can do cool stuff
  boolean update() {
    // send the ir code via pin 4
    IRsend irsend(4);
    irsend.begin();
    delay(4);
    irsend.sendNEC(REMOTE_KEY_CODES[this->keyPressed], 32, 0);
    return true;
  }
};
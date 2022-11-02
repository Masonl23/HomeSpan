#include "HomeSpan.h"
#include "IRsend.h"

// PIN USED TO SEND IR
#define IR_SEND_PIN 4

/** Keys suppported by device*/
enum REMOTES_KEY {
  BOSE_VOL_UP_K,
  BOSE_VOL_DOWN_K,
  BOSE_MUTE_K,
  
  HISENSE_TV_POWER_K,
  HISENSE_OK_K,
  HISENSE_BACK_K,
  HISENSE_HOME_K,
  HISENSE_LEFT_K,
  HISENSE_RIGHT_K,
  HISENSE_UP_K,
  HISENSE_DOWN_K,
  HISENSE_NETFLIX_K,
  HISENSE_UNDO_K,
  HISENSE_PLAY_K,

  XBOX_TOGGLE_POWER_K,
  XBOX_POWER_ON_K,
  XBOX_POWER_OFF_K,
  XBOX_A_K,
  XBOX_B_K,
  XBOX_X_K,
  XBOX_Y_K,
  XBOX_HOME_K,
  XBOX_LEFT_K,
  XBOX_RIGHT_K,
  XBOX_UP_K,
  XBOX_DOWN_K,

  NUM_K               // ENUM FOR CREATING SIZE OF ARRAY
};

// Codes for ir transmitter
uint32_t REMOTE_KEY_CODES[NUM_K] = {
  0x5dd2c03f,  // BOSE VOLUME UP
  0x5dd240bf,  // BOSE VOLUME DOWN
  0x5dd2807f,  // BOSE MUTE
  
  0x57e3e817,  // HISENSE TV POWER
  0x57E354AB,  // HISENSE OK
  0x57E36699,  // HISENSE BACK
  0x57E3C03F,  // HISENSE HOME
  0x57E37887,  // HISENSE LEFT
  0x57E3B44B,  // HISENSE RIGHT
  0x57E39867,  // HISENSE UP 
  0x57E3CC33,  // HISENSE DOWN
  0x57E34AB5,  // HISENSE NETFLIX
  0x57E31EE1,  // HISENSE UNDO
  0x57e332cd,  // HISENSE PLAY

  0x011bf40b,  // XBOX POWER TOGGLE
  0x011b54ab,  // XBOX POWER ON
  0x011b946b,  // XBOX POWER OFF
  0x011b6699,  // XBOX A
  0x011ba659,  // XBOX B
  0x011b16e9,  // XBOX X
  0x011be619,  // XBOX Y
  0x011b26d9,  // XBOX HOME
  0x011b04fb,  // XBOX LEFT
  0x011b847b,  // XBOX RIGHT
  0x011b7887,  // XBOX UP
  0x011bf807   // XBOX DOWN
};

// struct holds data for ir transmitter
struct IR_TRANSMITTER : Service::LightBulb {
  REMOTES_KEY keyPressed;
  SpanCharacteristic *code;

  // CREATE IR TRANSMITTER DEIVCE AND PUT INFORMATION IN IT
  IR_TRANSMITTER(REMOTES_KEY keyDesired)
    : Service::LightBulb() {
    this->keyPressed = keyDesired;
    code = new Characteristic::On();
  }

  // OVERLOAD UPDATE WITH IR SENDING CAPABILITIES
  boolean update() {
    // CREATE IRSEND OBJECT WITH CORRECT PIN DEFINED AT TOP
    IRsend irsend(IR_SEND_PIN);
    irsend.begin();
    // GIVE TIME TO INSTANTIATE 
    delay(4);
    // SEND THE CODE BASED ON PARAM
    irsend.sendNEC(REMOTE_KEY_CODES[this->keyPressed], 32, 0);
    return true;
  }
};
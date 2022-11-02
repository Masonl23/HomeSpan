/**
  Description: Code for Tv and sound control. Uses example from HomeSpan with altercations using 
  so we can send IR signals from ESP32.
  
  Author: Mason Lopez

*/

#include <Arduino.h>
#include "HomeSpan.h"
#include "IR_TRANSMITTER.h"
#include <IRremoteESP8266.h>
#include <EEPROM.h>

bool restart = false;

void setup() {
  // put your setup code here, to run once:
  EEPROM.begin(2);
  if (EEPROM.read(0) == 0) {
    if (EEPROM.read(1) == 0) {
      EEPROM.write(0, 1);
      EEPROM.commit();
      restart = true;
    } else {
      EEPROM.write(1, 0);
      EEPROM.write(0, 0);
      EEPROM.commit();
    }
  } else if (EEPROM.read(0) == 1 && EEPROM.read(1) == 1) {
    EEPROM.write(1, 0);
    EEPROM.write(0, 0);
    EEPROM.commit();
  }
    
  Serial.begin(115200);

  // create the homespan device
  homeSpan.enableOTA();
  homeSpan.begin(Category::Lighting, "TV AND SOUND");

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("TV POWER");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(HISENSE_TV_POWER_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("MUTE");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(BOSE_MUTE_K);


  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("VOL UP");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(BOSE_VOL_UP_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("VOL DOWN");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(BOSE_VOL_DOWN_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("OK");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(HISENSE_OK_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("BACK");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(HISENSE_BACK_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("HOME");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(HISENSE_HOME_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("LEFT KEY");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(HISENSE_LEFT_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("RIGHT KEY");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("Hisense Button");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(HISENSE_RIGHT_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("RIGHT KEY Button");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("Hisense Button");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(HISENSE_RIGHT_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("UP");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("Hisense Button");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(HISENSE_UP_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("DOWN");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("Hisense Button");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(HISENSE_DOWN_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("NETFLIX");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("Hisense Button");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(HISENSE_NETFLIX_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("UNDO");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("Hisense button");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(HISENSE_UNDO_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("PLAY B");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("Hisense button");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(HISENSE_PLAY_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("XBOX POWER TOGGLE");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("XBOX BUTTON");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(XBOX_TOGGLE_POWER_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("XBOX POWER ON");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("XBOX BUTTON");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(XBOX_POWER_ON_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("XBOX POWER OFF");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("XBOX BUTTON");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(XBOX_POWER_OFF_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("XBOX A");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("XBOX BUTTON");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(XBOX_A_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("XBOX B");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("XBOX BUTTON");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(XBOX_B_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("XBOX X");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("XBOX BUTTON");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(XBOX_X_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("XBOX Y");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("XBOX BUTTON");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(XBOX_Y_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("XBOX HOME");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("XBOX BUTTON");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(XBOX_HOME_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("XBOX LEFT");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("XBOX BUTTON");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(XBOX_LEFT_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("XBOX RIGHT");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("XBOX BUTTON");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(XBOX_RIGHT_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("XBOX UP");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("XBOX BUTTON");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(XBOX_UP_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("XBOX DOWN");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("XBOX BUTTON");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(XBOX_DOWN_K);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (restart){
    EEPROM.write(1, 1);
    EEPROM.commit();
    delay(300);
    ESP.restart();
  }
  homeSpan.updateDatabase();
  
  homeSpan.poll();
}

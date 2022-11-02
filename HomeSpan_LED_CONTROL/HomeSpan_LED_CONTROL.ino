/**
  Description: Code for controlling LEDS via homekit.

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
  homeSpan.begin(Category::Lighting, "LED");

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("LED POWER");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(POWER_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("RED");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(RED_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("BLUE");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(BLUE_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("GREEN");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(GREEN_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("WHITE");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(WHITE_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("SOFT ORANGE");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(SOFT_ORANGE_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("MINT");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(MINT_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("VIOLET");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(VIOLET_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("NULLE");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(SOFT_LIGHT_K);

    new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("SOFT LIGHT");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(SOFT_LIGHT_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("COLGATE");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(COLGATE_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("LIGHT UV");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(LIGHT_UV_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("NUCLEAR");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(NUCLEAR_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("UV");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(UV_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("INCREASE LIGHT");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(INC_LIGHT_K);

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("DECREASE LIGHT");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("1");
  new Characteristic::Model("cheap led");
  new Characteristic::FirmwareRevision("1");
  new Characteristic::Identify();
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1");
  new IR_TRANSMITTER(DEC_LIGHT_K);
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

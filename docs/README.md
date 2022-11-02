# Welcome to IR Blaster ESP32 fork of HomeSpan
In this fork of HomeSpan is modified version to allow you to create a crude IR Blaster that can control devices with ease using HomeKit widgets that can be used from iPhone among other Apple devices. All credit of base code to [HomeSpan](https://github.com/HomeSpan/HomeSpan).



# Files

HomeSpan_LED_CONTROL folder contains example code of creating accessories to control devices using HomeSpan, similarly HomeSpan_TV_AND_SOUND folder contains example code controlling TV, Bose Audio system and Xbox One via IR commands.
# Notes
This is a rough and crude way to implement this, however it does work. In the included examples you will find lines of code dealing with reading from EEPROM, this is a workaround I found when uploading and programming over the air since I had to manually cycle its power by unplugging it, this became tiresome as they are not in convent spots to get to. This workaround removes the need to do so as it restarts itself every time you restart or reprogram the board. So once you upload OTA and its finished it will restart it self , and then restart it self again. EEPROM **is a limited write/read resource** so remove it you are worried, but you should not have an issue as it requires thousands of operations.
## How to 

 - You will need to have a 
	 - IR reciever 
	 - IR transmitter 
	 - ESP32 board, any flavor
	 
	Note that the IR receiver isn't necessary if you can find the codes online, otherwise you will need one to decode and record your desired commands.
- Once you have your codes figured out create a list and replace the items in the IR_TRANSMITTER.h file in both the enum *REMOTES_KEY* and uint32_t *REMOTE_KEY_CODES* array. You will need to make sure you match the order you add the items in both enum.
- Upload the code and then reference the HomeSpan repo to follow the instructions to add to your HomeKit.

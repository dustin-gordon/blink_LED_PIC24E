// Pic24ep512gu810 implementation

#include <stdint.h>
#include "Compiler.h" 
#include "ConfigurationBits.h"

// Assume LEDs are connected to pins A4 - A7

// initialize the LEDs
void initLeds() {
	TRISD &= 0xFF0F;  // 1111 1111 0000 1111 = 0xFF0F
}

// turn one selected LED on
void turnLedOn(uint8_t selection) {
	LATD |= 1 << (selection + 1);
}

// turn one selected LED off
void turnLedOff(uint8_t selection) {
	LATD &= ~(1 << (selection + 1));
}

// toggle selected LED
void toggleLed(uint8_t selection) {
	LATD ^= (1 << (selection + 1));
}

// set a value to the LED
void setLed(uint8_t value) {
	LATD = (LATD & 0xFF0F) | ((value & 0xF0) << 1);
}

/* 
// This file is subject to the terms and conditions defined in
// file 'LICENSE.md', which is part of this source code package.
*/

// The "Arduino.h" header file is intended to only be included by C++ sources.

#ifndef _ARDUINO_MBED_BRIDGE_ARDUINO_H_
#define _ARDUINO_MBED_BRIDGE_ARDUINO_H_

#include "mbed.h"

#define PinMode Arduino_PinMode         // note: this changes the Arduino API for mbed compatibility - use Arduino_PinMode where PinMode was specified in the Arduino API
#include "core-api/api/ArduinoAPI.h"
#undef PinMode

#include "core-extend/ArduinoAPI.h"

#include "bridge/pins.h"

#include "variant.h"                    // user-supplied

#endif // _ARDUINO_MBED_BRIDGE_ARDUINO_H_

/*
Copyright (c) 2020 SparkFun Electronics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef _ARDUINO_MBED_BRIDGE_EXTEND_COMMON_H_
#define _ARDUINO_MBED_BRIDGE_EXTEND_COMMON_H_

#include "Arduino.h"

void            indexPinMode(pin_size_t index, Arduino_PinMode pinMode);
void            pinMode(PinName pinName, Arduino_PinMode pinMode);

void            indexDigitalWrite(pin_size_t index, PinStatus val);
void            digitalWrite(PinName pinName, PinStatus val);

PinStatus       indexDigitalRead(pin_size_t index);
PinStatus       digitalRead(PinName pinName);

void            indexAnalogWriteDAC(pin_size_t index, int val);
void            analogWriteDAC(PinName pinName, int val);
void            analogWriteDAC(pin_size_t pinNumber, int val);

void            indexAnalogWrite(pin_size_t index, int val);
void            analogWrite(PinName pinName, int val);

#ifdef __cplusplus

unsigned long   indexPulseIn(pin_size_t index, uint8_t state, unsigned long timeout = 1000000L);
unsigned long   pulseIn(PinName pinName, uint8_t state, unsigned long timeout = 1000000L);
unsigned long   indexPulseInLong(pin_size_t index, uint8_t state, unsigned long timeout = 1000000L);
unsigned long   pulseInLong(PinName pinName, uint8_t state, unsigned long timeout = 1000000L);

#endif // __cplusplus

#endif // _ARDUINO_MBED_BRIDGE_EXTEND_COMMON_H_

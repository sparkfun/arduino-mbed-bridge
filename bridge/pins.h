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

#ifndef _ARDUINO_MBED_BRIDGE_PINS_H_
#define _ARDUINO_MBED_BRIDGE_PINS_H_

#include "Arduino.h"

typedef struct _PinState {
    PinName name;
    pin_size_t number;
    InterruptIn* irq;
    // PwmOut* pwm; // todo: implement
    // AnalogOut* dac; // todo: implement this
    DigitalInOut* gpio;
} PinState;

pin_size_t pinIndexByName(PinName name);
pin_size_t pinIndexByNumber(pin_size_t number);

PinName pinNameByIndex(pin_size_t index);
pin_size_t pinNumberByIndex(pin_size_t index);

#define pinIRQByIndex(I) variantPinStates[I].irq
#define pinPWMByIndex(I) variantPinStates[I].pwm
#define pinDACByIndex(I) variantPinStates[I].dac
#define pinGPIOByIndex(I) variantPinStates[I].gpio

extern const pin_size_t variantPinCount;
extern PinState variantPinStates[];

#endif // _ARDUINO_MBED_BRIDGE_PINS_H_
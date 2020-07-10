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

#include "mbed.h"

#define PinMode Arduino_PinMode
#include "core-api/api/Common.h"
#undef PinMode

#include "core-extend/Common.h"
#include "bridge/pins.h"

// unsigned long indexPulseIn(pin_size_t index, uint8_t state, unsigned long timeout){
//     standInFunc();
//     return 0;
// }

unsigned long pulseIn(PinName pinName, uint8_t state, unsigned long timeout){
    pin_size_t index = pinIndexByName(pinName);
    if( index == variantPinCount ){ return 0; }
    return indexPulseIn(index, state, timeout);
}

unsigned long pulseIn(pin_size_t pinNumber, uint8_t state, unsigned long timeout){
    pin_size_t index = pinIndexByNumber(pinNumber);
    if( index == variantPinCount ){ return 0; }
    return indexPulseIn(index, state, timeout);
}

unsigned long indexPulseInLong(pin_size_t index, uint8_t state, unsigned long timeout){
    return indexPulseIn(index, state, timeout); // pulseIn and pulseInLong are identical
}

unsigned long pulseInLong(PinName pinName, uint8_t state, unsigned long timeout){
    pin_size_t index = pinIndexByName(pinName);
    if( index == variantPinCount ){ return 0; }
    return pulseInLong(index, state, timeout);
}

unsigned long pulseInLong(pin_size_t pinNumber, uint8_t state, unsigned long timeout){
    pin_size_t index = pinIndexByNumber(pinNumber);
    if( index == variantPinCount ){ return 0; }
    return pulseInLong(index, state, timeout);
}

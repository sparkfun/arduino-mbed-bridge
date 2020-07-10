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

#include "bridge/pins.h"

#define standInFunc() printf("Stand-In for '%s' [file: %s, line: %d]\n", __FUNCTION__, __FILE__, __LINE__)

void indexPinMode(pin_size_t index, Arduino_PinMode pinMode){
    standInFunc();
    printf("\tindex: %d\n", index);
    DigitalInOut* gpio = pinGPIOByIndex(index);
    if( gpio == NULL ){
        gpio = new DigitalInOut(pinNameByIndex(index));
        printf("\tcreating a new DigitalInOut object! 0x%08X\n", (unsigned int)gpio);
    }
    printf("\tgpio = 0x%08X\n", (unsigned int)gpio);
    pinGPIOByIndex(index) = gpio;

    switch (pinMode) {
        case INPUT:
            gpio->input();
            gpio->mode(PullNone);
            break;
        case OUTPUT:
            gpio->output();
            break;
        case INPUT_PULLUP:
            gpio->input();
            gpio->mode(PullUp);
            break;
        case INPUT_PULLDOWN:
        default:
            gpio->input();
            gpio->mode(PullDown);
            break;
    }
}

void pinMode(pin_size_t pinNumber, Arduino_PinMode pinMode){
    pin_size_t index = pinIndexByNumber(pinNumber);
    printf("via PinNumber\n");
    if( index == variantPinCount ){ return; }
    indexPinMode(index, pinMode);
}

void pinMode(PinName pinName, Arduino_PinMode pinMode){
    pin_size_t index = pinIndexByName(pinName);
    printf("via PinName\n");
    if( index == variantPinCount ){ return; }
    indexPinMode(index, pinMode);
}

void indexDigitalWrite(pin_size_t index, PinStatus val){
    mbed::DigitalInOut* gpio = pinGPIOByIndex(index);
    if (gpio == NULL) {
        gpio = new mbed::DigitalInOut(pinNameByIndex(index), PIN_OUTPUT, PullNone, val);
        pinGPIOByIndex(index) = gpio;
    }
    gpio->write(val);
}

void digitalWrite(pin_size_t pinNumber, PinStatus val){
    pin_size_t index = pinIndexByNumber(pinNumber);
    printf("via PinNumber\n");
    if( index == variantPinCount ){ return; }
    indexDigitalWrite(index, val);
}

void digitalWrite(PinName pinName, PinStatus val){
    pin_size_t index = pinIndexByName(pinName);
    printf("via PinName\n");
    if( index == variantPinCount ){ return; }
    indexDigitalWrite(index, val);
}

PinStatus indexDigitalRead(pin_size_t index){
    mbed::DigitalInOut* gpio = pinGPIOByIndex(index);
    if (gpio == NULL) {
        gpio = new mbed::DigitalInOut(pinNameByIndex(index), PIN_INPUT, PullNone, 0);
        pinGPIOByIndex(index) = gpio;
    }
    return (PinStatus) gpio->read();
}

PinStatus digitalRead(pin_size_t pinNumber){
    pin_size_t index = pinIndexByNumber(pinNumber);
    printf("via PinNumber\n");
    if( index == variantPinCount ){ return LOW; }
    return indexDigitalRead(index);
}

PinStatus digitalRead(PinName pinName){
    pin_size_t index = pinIndexByName(pinName);
    printf("via PinName\n");
    if( index == variantPinCount ){ return LOW; }
    return indexDigitalRead(index);
}

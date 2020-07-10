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

void indexMode(pin_size_t index, Arduino_PinMode pinMode){
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
    indexMode(index, pinMode);
}

void pinMode(PinName pinName, Arduino_PinMode pinMode){
    pin_size_t index = pinIndexByName(pinName);
    printf("via PinName\n");
    if( index == variantPinCount ){ return; }
    indexMode(index, pinMode);
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

// static int res_analog_w = 8;
// static int res_analog_r = 10;
void indexAnalogWriteDAC(pin_size_t index, int val){
    standInFunc();
    // // todo: support mbed DAC modules
    // mbed::AnalogOut* dac = pinDACByIndex(index);
    // if (dac == NULL) {
    //     dac = new mbed::AnalogOut(pinNameByIndex(index));
    //     pinDACByIndex(index) = dac;
    // }
    // float percent = (float)val/(float)(1 << res_analog_w);
    // dac->write(percent);
}

void analogWriteDAC(PinName pinName, int val){
    pin_size_t index = pinIndexByName(pinName);
    if( index == variantPinCount ){ return; }
    indexAnalogWriteDAC(index, val);
}

void analogWriteDAC(pin_size_t pinNumber, int val){
    pin_size_t index = pinIndexByNumber(pinNumber);
    if( index == variantPinCount ){ return; }
    indexAnalogWriteDAC(index, val);
}

// void indexAnalogWrite(pin_size_t index, int val){
//     standInFunc();
//     // mbed::PwmOut* pwm = pinPWMByIndex(index);
//     // if (pwm == NULL) {
//     //     pwm = new mbed::PwmOut(pinNameByIndex(index));
//     //     pinPWMByIndex(index) = pwm;
//     // }
//     // pwm->period_ms(2);
//     // float percent = (float)val/(float)(1 << res_analog_w);
//     // pwm->write(percent);
// }

void analogWrite(PinName pinName, int val){
    pin_size_t index = pinIndexByName(pinName);
    if( index == variantPinCount ){ return; }
    indexAnalogWrite(index, val);
}

void analogWrite(pin_size_t pinNumber, int val){
    pin_size_t index = pinIndexByNumber(pinNumber);
    if( index == variantPinCount ){ return; }
    indexAnalogWrite(index, val);
}

// #if DEVICE_LPTICKER
// static mbed::LowPowerTimer t;
// #else
static mbed::Timer t;
// #endif

using namespace std::chrono_literals;
using namespace std::chrono;

void initTimer(void){
    t.start();
}

unsigned long millis(void){
    return duration_cast<milliseconds>(t.elapsed_time()).count();
}

unsigned long micros(void){
    return t.elapsed_time().count();
}

void delay(unsigned long ms){
#ifndef NO_RTOS
  rtos::ThisThread::sleep_for(ms * 1ms);
#else
  wait_us(ms * 1000);
#endif
}

void delayMicroseconds(unsigned int us){
    wait_us(us);
}

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

void init(void){
    initTimer();
}

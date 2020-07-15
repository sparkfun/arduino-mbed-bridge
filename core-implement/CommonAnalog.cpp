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

#define standInFunc() printf("Stand-In for '%s' [file: %s, line: %d]\n", __FUNCTION__, __FILE__, __LINE__)

// int indexAnalogRead(pin_size_t index){
//     // todo: support mbed AnalogIn modules
//     mbed::AnalogIn* adc = pinADCByIndex(index);
//     if (adc == NULL) {
//         adc = new mbed::AnalogIn(name);
//         pinADCByIndex(index) = adc;
// #ifdef ANALOG_CONFIG
//         if (isAdcConfigChanged) {
//             adc->configure(adcCurrentConfig);
//         }
// #endif
//     }
//     return (adc->read_u16() >> (16 - read_resolution));
// }

int analogRead(PinName pinName){
    pin_size_t index = pinIndexByName(pinName);
    if( index == variantPinCount ){ return; }
    return indexAnalogRead(index);
}

int analogRead(pin_size_t pinNumber){
    pin_size_t index = pinIndexByNumber(pinNumber);
    if( index == variantPinCount ){ return; }
    return indexAnalogRead(index);
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

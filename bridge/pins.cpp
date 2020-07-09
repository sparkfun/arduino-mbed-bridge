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

#include "bridge/pins.h"

pin_size_t pinIndexByName(PinName name){
    pin_size_t index = 0;
    while(index < variantPinCount){
        if(variantPinStates[index].name == name){ return index; }
        index++;
    }
    return variantPinCount;
}

pin_size_t pinIndexByNumber(pin_size_t number){
    pin_size_t index = 0;
    while(index < variantPinCount){
        if(variantPinStates[index].number == number){ return index; }
        index++;
    }
    return variantPinCount;
}

PinName pinNameByIndex(pin_size_t index){
    if(index >= variantPinCount){ return NC; }
    return variantPinStates[index].name;
}

pin_size_t pinNumberByIndex(pin_size_t index){
    if(index >= variantPinCount){ return (pin_size_t)NC; }
    return variantPinStates[index].number;
}
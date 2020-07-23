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

#ifndef _ARDUINO_MBED_BRIDGE_CORE_EXTEND_HARDWARESERIAL_H_
#define _ARDUINO_MBED_BRIDGE_CORE_EXTEND_HARDWARESERIAL_H_

#include "bridge/pins.h"
#include "core-api/api/RingBuffer.h"

#define RX_BUF_LEN (256)

class UART : public HardwareSerial, public mbed::UnbufferedSerial {
private:
    RingBufferN<RX_BUF_LEN> _rxbuf;

protected:
public:
    UART(PinName tx, PinName rx, PinName rts = NC, PinName cts = NC);
	UART(pin_size_t tx, pin_size_t rx, pin_size_t rts = variantPinCount, pin_size_t cts = variantPinCount);
    UART( void );
	~UART( void );

    void rxISR( void );

    void begin(unsigned long baudrate, uint16_t config);
    void begin(unsigned long baudrate);
    void end( void );
    int available(void);
    int peek(void);
    int read(void);
    void flush(void);
    size_t write(uint8_t c);
    size_t write(const uint8_t* buffer, size_t size);
    using Print::write;
    int printf(const char *format, ...);
    operator bool(){
        return true;
    }
};

extern UART Serial;

#endif // _ARDUINO_MBED_BRIDGE_CORE_EXTEND_HARDWARESERIAL_H_

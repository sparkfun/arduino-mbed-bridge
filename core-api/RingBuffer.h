/* 
// This file is subject to the terms and conditions defined in
// file 'LICENSE.md', which is part of this source code package.
*/

//I absolutely hate this work-around, but including core-api/api in my include paths just breaks everything
//Most functionality is included via mbed-bridge/Arduino.h, but this header keeps causing problem for people
//because it is included directly by many libraries... so here we are.

//It would be nice to get to the point where including core-api/api in my include paths doesn't break everything, but until then this works.

#ifndef _ARDUINO_MBED_BRIDGE_CORE_API_RINGBUFFER_H_
#define _ARDUINO_MBED_BRIDGE_CORE_API_RINGBUFFER_H_

#include "core-api/api/RingBuffer.h"

#endif // _ARDUINO_MBED_BRIDGE_CORE_API_RINGBUFFER_H_

/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018, hathach for Adafruit
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef USBSERIAL_H_
#define USBSERIAL_H_

#ifdef NRF52840_XXAA

#include "Adafruit_USBDevice.h"
#include "Stream.h"

class USBSerial : public Stream, Adafruit_USBInterface
{
public:
	USBSerial(void);

	// fron Adafruit_USBInterface
	virtual uint16_t getDescriptor(uint8_t* buf, uint16_t bufsize);

	void setPins(uint8_t pin_rx, uint8_t pin_tx) { (void) pin_rx; (void) pin_tx; }
	void begin(uint32_t baud_count);
	void begin(uint32_t baud, uint8_t config);
	void end(void);

	virtual int available(void);
	virtual int peek(void);
	virtual int read(void);
	virtual void flush(void);
	virtual size_t write(uint8_t);
	virtual size_t write(const uint8_t *buffer, size_t size);
	size_t write(const char *buffer, size_t size) {
	  return write((const uint8_t *)buffer, size);
	}
	operator bool();

	size_t readBytes(char *buffer, size_t length);
	size_t readBytes(uint8_t *buffer, size_t length) { return readBytes((char *)buffer, length); }
};


extern USBSerial Serial;

#endif

#endif /* USBSERIAL_H_ */

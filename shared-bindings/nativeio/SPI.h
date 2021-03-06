/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Scott Shawcroft
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

#ifndef __MICROPY_INCLUDED_SHARED_BINDINGS_NATIVEIO_SPI_H__
#define __MICROPY_INCLUDED_SHARED_BINDINGS_NATIVEIO_SPI_H__

#include "py/obj.h"

#include "common-hal/microcontroller/types.h"
#include "common-hal/nativeio/types.h"

// Type object used in Python. Should be shared between ports.
extern const mp_obj_type_t nativeio_spi_type;

// Construct an underlying SPI object.
extern void common_hal_nativeio_spi_construct(nativeio_spi_obj_t *self,
    const mcu_pin_obj_t * clock, const mcu_pin_obj_t * mosi,
    const mcu_pin_obj_t * miso);

extern void common_hal_nativeio_spi_deinit(nativeio_spi_obj_t *self);

extern bool common_hal_nativeio_spi_configure(nativeio_spi_obj_t *self, uint32_t baudrate, uint8_t polarity, uint8_t phase, uint8_t bits);

extern bool common_hal_nativeio_spi_try_lock(nativeio_spi_obj_t *self);
extern bool common_hal_nativeio_spi_has_lock(nativeio_spi_obj_t *self);
extern void common_hal_nativeio_spi_unlock(nativeio_spi_obj_t *self);

// Writes out the given data.
extern bool common_hal_nativeio_spi_write(nativeio_spi_obj_t *self, const uint8_t *data, size_t len);

// Reads in len bytes while outputting zeroes.
extern bool common_hal_nativeio_spi_read(nativeio_spi_obj_t *self, uint8_t *data, size_t len);

#endif // __MICROPY_INCLUDED_SHARED_BINDINGS_NATIVEIO_SPI_H__

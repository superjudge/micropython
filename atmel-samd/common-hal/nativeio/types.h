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

// This defines the types used to underly the standard nativeio Python objects.
// The shared API is defined in terms of these types.

#ifndef __MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_NATIVEIO_TYPES_H__
#define __MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_NATIVEIO_TYPES_H__

#include "common-hal/microcontroller/types.h"

// Don't reorder these includes because they are dependencies of adc_feature.h.
// They should really be included by adc_feature.h.
#include <compiler.h>
#include "asf/sam0/drivers/system/clock/gclk.h"
#include "asf/sam0/utils/cmsis/samd21/include/component/adc.h"
#include "asf/sam0/drivers/adc/adc_sam_d_r/adc_feature.h"

#include "asf/sam0/drivers/dac/dac.h"
#include "asf/sam0/drivers/sercom/i2c/i2c_master.h"
#include "asf/sam0/drivers/sercom/spi/spi.h"
#include "asf/sam0/drivers/tc/tc.h"
#include "asf/sam0/drivers/tcc/tcc.h"

#include "py/obj.h"

typedef struct {
    mp_obj_base_t base;
    const mcu_pin_obj_t * pin;
    struct adc_module adc_instance;
} nativeio_analogin_obj_t;

typedef struct {
    mp_obj_base_t base;
    struct dac_module dac_instance;
} nativeio_analogout_obj_t;

typedef struct {
    mp_obj_base_t base;
    const mcu_pin_obj_t * pin;
    bool output;
    bool open_drain;
} nativeio_digitalinout_obj_t;

typedef struct {
    mp_obj_base_t base;
    struct i2c_master_module i2c_master_instance;
    bool has_lock;
} nativeio_i2c_obj_t;

typedef struct _machine_spi_obj_t {
    mp_obj_base_t base;
    struct spi_module spi_master_instance;
    bool has_lock;
} nativeio_spi_obj_t;

typedef struct {
    mp_obj_base_t base;
    const mcu_pin_obj_t *pin;
    bool using_primary_timer;
    struct tc_module tc_instance;
    struct tcc_module tcc_instance;
} nativeio_pwmout_obj_t;

#endif // __MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_NATIVEIO_TYPES_H__

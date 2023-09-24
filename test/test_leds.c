/*
 * MIT License
 * Copyright (c) 2023 Francesco Cavina <francescocavina98@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or, sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of he Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAS PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY. WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE
 */

/*
 * @file:    test_leds.c
 * @date:    24/09/2023
 * @author:  Francesco Cavina <francescocavina98@gmail.com>
 * @version: v1.0.0
 *
 * @brief:   This file has the code for the unit tests using the Ceedling framework.
 */

/*
 * DRIVER TESTS:
 *
 * 01) When starting the driver, all LEDs should be off.
 * 02) With all LEDs off, it must be possible to turn on a certain LED.
 * 03) It must be possible to turn off a lit LED.
 * 04) It must be possible to turn an LED on and off with some LEDs already on and others already
 * off. 05) It must be possible to query the status of a lit LED. 06) It must be possible to query
 * the status of an off LED. 07) With all LEDs off, it must be possible to turn on all LEDs
 * together. 08) With all LEDs on, it must be possible to turn off all LEDs together. 09) It must be
 * possible to switch LEDs 1 and 16 on and off and to check that they have been switched on and off
 * respectively. 10) LEDs should not be turned on or off if the indicated LED number is outside the
 * limits (must be between 1 and 16).
 */

/* --- Headers files inclusions ---------------------------------------------------------------- */
#include "unity.h"
#include "leds.h"

/* --- Macros definitions ---------------------------------------------------------------------- */

/* --- Private data type declarations ---------------------------------------------------------- */

/* --- Private variable declarations ----------------------------------------------------------- */

/* --- Private function declarations ----------------------------------------------------------- */

/* --- Public variable definitions ------------------------------------------------------------- */

/* --- Private variable definitions ------------------------------------------------------------ */

/* --- Private function implementation --------------------------------------------------------- */

/* --- Public function implementation ---------------------------------------------------------- */

// 01) When starting the driver, all LEDs should be off.
void test_all_leds_start_off(void) {

    /* Define virtual memory address */
    uint16_t virtual_port = 0xFFFF;

    /* Initialize LEDs */
    LEDS_Init(&virtual_port);

    /* Test if LEDs are off */
    TEST_ASSERT_EQUAL(0, virtual_port);
}

// 03) It must be possible to turn off a lit LED.
// 04) It must be possible to turn an LED on and off with some LEDs already on and others already
// off. 05) It must be possible to query the status of a lit LED. 06) It must be possible to query
// the status of an off LED. 07) With all LEDs off, it must be possible to turn on all LEDs
// together. 08) With all LEDs on, it must be possible to turn off all LEDs together. 09) It must be
// possible to switch LEDs 1 and 16 on and off and to check that they have been switched on and off
// respectively. 10) LEDs should not be turned on or off if the indicated LED number is outside the
// limits (must be between 1 and 16).

/* --- End of file ----------------------------------------------------------------------------- */

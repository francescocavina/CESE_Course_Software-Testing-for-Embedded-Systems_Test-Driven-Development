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

/* --- Headers files inclusions ---------------------------------------------------------------- */
#include "unity.h"
#include "leds.h"

/* --- Macros definitions ---------------------------------------------------------------------- */

/* --- Private data type declarations ---------------------------------------------------------- */

/* --- Private variable declarations ----------------------------------------------------------- */
static uint16_t virtual_port = 0xFFFF;
/* --- Private function declarations ----------------------------------------------------------- */

/* --- Public variable definitions ------------------------------------------------------------- */

/* --- Private variable definitions ------------------------------------------------------------ */

/* --- Private function implementation --------------------------------------------------------- */

/* --- Public function implementation ---------------------------------------------------------- */

// Set up function for all tests
void setUp(void) {

    /* Initialize LEDs */
    LEDS_Init(&virtual_port);
}

// 01) When starting the driver, all LEDs should be off.
void test_all_leds_start_off(void) {

    /* Define virtual memory address */
    uint16_t virtual_port = 0xFFFF;

    /* Initialize LEDs */
    LEDS_Init(&virtual_port);

    /* Test if LEDs are off */
    TEST_ASSERT_EQUAL(0, virtual_port);
}

// 02) With all LEDs off, it must be possible to turn on a certain LED.
void test_turn_on_led_with_all_leds_off(void) {

    /* Turn on LED No. 5 */
    LEDS_TurnOn(5);

    /* Test if  LED No. 5 is on */
    TEST_ASSERT_BIT_HIGH(4, virtual_port);

    /* Test if  other LEDs are off */
    TEST_ASSERT_BITS_LOW(~(1 << 4), virtual_port);
}

// 03) It must be possible to turn off a lit LED.
void test_turn_off_lit_led(void) {

    /* Turn on LED No. 5 */
    LEDS_TurnOn(5);

    /* Turn off LED No. 5 */
    LEDS_TurnOff(5);

    /* Test if LED No. 5 is off */
    TEST_ASSERT_EQUAL(0, virtual_port);
}

// 04) It must be possible to turn an LED on and off with some LEDs already on and others already
// off.
void test_turn_on_multiple_leds(void) {

    /* Turn on LED No. 5 */
    LEDS_TurnOn(5);

    /* Turn on LED No. 3 */
    LEDS_TurnOn(3);

    /* Turn on LED No. 3 */
    LEDS_TurnOn(3);

    /* Test if LED No. 5 is on */
    TEST_ASSERT_BIT_HIGH(4, virtual_port);

    /* Test if LED No. 3 is on */
    TEST_ASSERT_BIT_HIGH(2, virtual_port);
}

// 04) It must be possible to turn an LED on and off with some LEDs already on and others already
// off.
void test_turn_on_and_turn_off_multiple_leds(void) {

    /* Turn on LED No. 5 */
    LEDS_TurnOn(5);

    /* Turn on LED No. 3 */
    LEDS_TurnOn(3);

    /* Turn on LED No. 3 */
    LEDS_TurnOn(3);

    /* Turn off LED No. 5 */
    LEDS_TurnOff(5);

    /* Turn off LED No. 2 */
    LEDS_TurnOff(2);

    /* Test if LED No. 5 is off */
    TEST_ASSERT_BIT_LOW(4, virtual_port);

    /* Test if LED No. 3 is on */
    TEST_ASSERT_BIT_HIGH(2, virtual_port);

    /* Test if LED No. 2 is off */
    TEST_ASSERT_BIT_LOW(1, virtual_port);

    /* Test if LED No. 3 is the only one on */
    TEST_ASSERT_BITS_LOW(~(1 << 2), virtual_port);
}

// 05) It must be possible to query the status of a lit LED.
void test_query_state_of_lit_LED(void) {

    uint8_t led_state;

    /* Turn on LED No. 12 */
    LEDS_TurnOn(12);

    /* Get LED state */
    led_state = LEDS_GetState(12);

    /* Test if LED state value is on */
    TEST_ASSERT_EQUAL(1, led_state);
}

// 06) It must be possible to query the status of an off LED.
void test_query_state_of_off_LED() {

    uint8_t led_state;

    /* Turn on LED No. 12 */
    LEDS_TurnOn(12);

    /* Turn off LED No. 12 */
    LEDS_TurnOff(12);

    /* Get LED state */
    led_state = LEDS_GetState(12);

    /* Test if LED state value is off */
    TEST_ASSERT_EQUAL(0, led_state);
}

// 07) With all LEDs off, it must be possible to turn on all LEDs together.
void test_turn_on_all_leds_with_all_leds_off(void) {

    /* Turn on all LEDs */
    LEDS_TurnOnAll();

    /* Test if all LEDs are on */
    TEST_ASSERT_EQUAL(65535, virtual_port);
}

// 08) With all LEDs on, it must be possible to turn off all LEDs together.
void test_turn_off_all_leds_with_all_leds_on(void) {

    /* Turn on all LEDs */
    LEDS_TurnOnAll();

    /* Turn off all LEDs */
    LEDS_TurnOffAll();

    /* Test if all LEDs are on */
    TEST_ASSERT_EQUAL(0, virtual_port);
}

// 09) It must be possible to switch LEDs 1 and 16 on and off and to check that they have been
// switched on and off respectively.
void test_leds_1_and_16_with_function_turn_on(void) {

    /* Turn on LED No. 1 */
    LEDS_TurnOn(1);

    /* Turn on LED No. 16 */
    LEDS_TurnOn(16);

    /* Test if LED No. 1 is on */
    TEST_ASSERT_BIT_HIGH(0, virtual_port);

    /* Test if LED No. 16 is on */
    TEST_ASSERT_BIT_HIGH(15, virtual_port);
}

void test_leds_1_and_16_with_function_turn_off(void) {

    /* Turn on LED No. 1 */
    LEDS_TurnOn(1);

    /* Turn on LED No. 16 */
    LEDS_TurnOn(16);

    /* Turn off LED No. 1 */
    LEDS_TurnOff(1);

    /* Turn off LED No. 16 */
    LEDS_TurnOff(16);

    /* Test if LED No. 1 is off */
    TEST_ASSERT_BIT_LOW(0, virtual_port);

    /* Test if LED No. 16 is off */
    TEST_ASSERT_BIT_LOW(15, virtual_port);
}

void test_leds_1_and_16_with_function_get_state(void) {

    uint8_t led_state_1;
    uint8_t led_state_16;

    /* Turn on LED No. 1 */
    LEDS_TurnOn(1);

    /* Turn on LED No. 16 */
    LEDS_TurnOn(16);

    /* Get LED No. 1 state */
    led_state_1 = LEDS_GetState(1);

    /* Get LED No. 16 state */
    led_state_16 = LEDS_GetState(16);

    /* Test if LED No. 1 state value is on */
    TEST_ASSERT_EQUAL(1, led_state_1);

    /* Test if LED No. 16 state value is on */
    TEST_ASSERT_EQUAL(1, led_state_16);
}

/* --- End of file ----------------------------------------------------------------------------- */

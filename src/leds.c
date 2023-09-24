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
 * @file:    leds.c
 * @date:    24/09/2023
 * @author:  Francesco Cavina <francescocavina98@gmail.com>
 * @version: v1.0.0
 *
 * @brief:   Driver for LEDs.
 */

/* --- Headers files inclusions ---------------------------------------------------------------- */
#include "leds.h"

/* --- Macros definitions ---------------------------------------------------------------------- */
#define LED_OFFSET                                                                                 \
    (1) // Offset constant to substract to LED number, as LED number starts from 1 but bits start
        // from 0
#define LED_ON_STATE  (1)      // LED value for on state
#define LED_OFF_STATE (0)      // LED value for off state
#define ALL_LEDS_OFF  (0)      // Value for all LEDs off
#define ALL_LEDS_ON   (0xFFFF) // Value for all LEDS on

/* --- Private data type declarations ---------------------------------------------------------- */

/* --- Private variable declarations ----------------------------------------------------------- */
static uint16_t * port_address;

/* --- Private function declarations ----------------------------------------------------------- */
/**
 * @brief
 * @param
 * @retval
 */
static uint16_t ledToMask(unsigned int led);
/* --- Public variable definitions ------------------------------------------------------------- */

/* --- Private variable definitions ------------------------------------------------------------ */

/* --- Private function implementation --------------------------------------------------------- */
static uint16_t ledToMask(unsigned int led) {

    /* Return mask */
    return (LED_ON_STATE << (led - LED_OFFSET));
}

/* --- Public function implementation ---------------------------------------------------------- */
void LEDS_Init(uint16_t * port) {

    port_address = port;

    /* Initialize LEDs */
    *port = ALL_LEDS_OFF;
}

void LEDS_TurnOn(unsigned int led) {

    /* Turn on LED */
    *port_address |= ledToMask(led);
}

void LEDS_TurnOff(unsigned int led) {

    /* Turn off LED */
    *port_address &= ~ledToMask(led);
}

uint8_t LEDS_GetState(unsigned int led) {

    /* Return LED state value */
    if (*port_address & ledToMask(led)) {
        return LED_ON_STATE;
    } else {
        return LED_OFF_STATE;
    }
}

void LEDS_TurnOnAll(void) {

    /* Turn on all LEDs */
    *port_address = ALL_LEDS_ON;
}

void LEDS_TurnOffAll(void) {

    /* Turn off all LEDs */
    *port_address = ALL_LEDS_OFF;
}

/* --- End of file ----------------------------------------------------------------------------- */

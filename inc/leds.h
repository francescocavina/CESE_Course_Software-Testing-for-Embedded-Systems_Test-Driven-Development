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
 * @file:    led.h
 * @date:    24/09/2023
 * @author:  Francesco Cavina <francescocavina98@gmail.com>
 * @version: v1.0.0
 *
 * @brief:   Driver for LEDs.
 */

#ifndef INC_LEDS_H
#define INC_LEDS_H

/* --- Headers files inclusions ---------------------------------------------------------------- */
#include <stdint.h>

/* --- C++ guard ------------------------------------------------------------------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* --- Public macros definitions --------------------------------------------------------------- */

/* --- Public data type declarations ----------------------------------------------------------- */

/* --- Public variable declarations ------------------------------------------------------------ */

/* --- Public function declarations ------------------------------------------------------------ */
/**
 * @brief  Initializes LEDs port.
 * @param  Pointer to LEDs port.
 * @retval None
 */
void LEDS_Init(uint16_t * port);

/**
 * @brief  Turns an LED on.
 * @param  No. of LED to turn on (1 to 16).
 * @retval None
 */
void LEDS_TurnOn(unsigned int led);

/**
 * @brief  Turns an LED off.
 * @param  No. of LED to turn off (1 to 16).
 * @retval None
 */
void LEDS_TurnOff(unsigned int led);

/**
 * @brief  Returns the state of an LED.
 * @param  No. of LED to read state.
 * @retval State of the LED read.
 */
uint8_t LEDS_GetState(unsigned int led);

/**
 * @brief  Turns all LEDs on.
 * @param  None
 * @retval None
 */
void LEDS_TurnOnAll(void);

/**
 * @brief  Turns all LEDs off.
 * @param  None
 * @retval NOne
 */
void LEDS_TurnOffAll(void);

/* --- End of C++ guard ------------------------------------------------------------------------ */
#ifdef __cplusplus
}
#endif

#endif /* INC_LEDS_H */

/* --- End of file ----------------------------------------------------------------------------- */

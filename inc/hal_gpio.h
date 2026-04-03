
#ifndef GPIO_H
#define GPIO_H

/* === Headers files inclusions ==================================================================================== */

#include <stdint.h>
#include <stdbool.h>

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

#define GPIO_PORT_A 1

#define GPIO_PORT_B 2

/* === Public data type declarations =============================================================================== */

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

void HalGpioSetDirection(uint8_t port, uint8_t pin, bool output);

bool HalGpioGetState(uint8_t port, uint8_t pin);

void HalGpioSetState(uint8_t port, uint8_t pin, bool active);

/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */

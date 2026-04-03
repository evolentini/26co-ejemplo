
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

typedef struct gpio_s * gpio_t;

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

gpio_t GpioCreate(uint8_t port, uint8_t pin);

void GpioSetDirection(gpio_t self, bool output);

bool GpioGetState(gpio_t self);

void GpioSetState(gpio_t self, bool active);

void GpioDetroy(gpio_t self);

/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */

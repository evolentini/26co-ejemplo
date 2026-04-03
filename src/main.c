/* === Headers files inclusions ================================================================ */

#include "gpio.h"
#include <stdbool.h>
/* === Macros definitions ====================================================================== */

#define LED_ROJO_PORT   GPIO_PORT_A
#define LED_ROJO_PIN    10

#define LED_VERDE_PORT   GPIO_PORT_B
#define LED_VERDE_PIN    14

/* === Private data type declarations ========================================================== */

/* === Private function declarations =========================================================== */

/* === Private variable definitions ============================================================ */

/* === Public variable definition  ============================================================= */

/* === Private function definitions ============================================================ */

/* === Public function implementation ========================================================== */

void main(void) {
    // GpioSetDirection(LED_ROJO_PORT, LED_ROJO_PIN);
    // GpioSetState(LED_ROJO_PORT, LED_VERDE_PIN, true);
    
    gpio_t led_rojo = GpioCreate(LED_ROJO_PORT, LED_ROJO_PIN);
    gpio_t led_verde = GpioCreate(LED_VERDE_PORT, LED_VERDE_PORT);
    gpio_t boton =  GpioCreate(LED_VERDE_PORT, LED_VERDE_PORT);

    GpioSetDirection(led_rojo, true);
    GpioSetState(led_rojo, true);

    GpioSetDirection(led_verde, true);
    GpioSetState(led_verde, GpioGetState(boton));
}

/* === End of documentation ==================================================================== */

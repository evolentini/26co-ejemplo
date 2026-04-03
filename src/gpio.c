/* === Headers files inclusions ================================================================ */

#include "gpio.h"
#include "hal_gpio.h"
#include <stddef.h>

/* === Macros definitions ====================================================================== */

#define MAX_INSTANCES 16

/* === Private data type declarations ========================================================== */

struct gpio_s {
    uint8_t port;
    uint8_t pin;
    bool output;
    bool state;
#ifdef USE_STATIC_MEM
    bool allocated;
#endif
};

/* === Private function declarations =========================================================== */

/* === Private variable definitions ============================================================ */

/* === Public variable definition  ============================================================= */

/* === Private function definitions ============================================================ */

#ifdef USE_STATIC_MEM
gpio_t GpioAllocate(void) {
    static struct gpio_s instances[MAX_INSTANCES] = {0};
    gpio_t self = NULL;

    for (int indice = 0; indice < MAX_INSTANCES; indice++) {
        if (!instances[indice].allocated) {
            self = &instances[indice];
            self->allocated = true;
            break;
        }
    }
    return self;
}
#endif

/* === Public function implementation ========================================================== */

gpio_t GpioCreate(uint8_t port, uint8_t pin) {
    gpio_t self;
#ifdef USE_STATIC_MEM
    self = GpioAllocate();
#else
    self = malloc(sizeof(struct gpio_s));
#endif
    if (self) {
        self->port = port;
        self->pin = pin;
        self->output = false;
        self->state = false;
    }
    return self;
}

void GpioSetDirection(gpio_t self, bool output) {
    HalGpioSetDirection(self->port, self->pin);
}

bool GpioGetState(gpio_t self) {
    if (self->output) {
        return self->state;
    } else {
        return HalGpioGetState(self->port, self->pin);
    }
}

void GpioSetState(gpio_t self, bool active) {
    if (self->output) {
        HalGpioSetState(self->port, self->pin, active);
        self->state = active;
    }
}

void GpioDetroy(gpio_t self) {
    // free(self);
    self->allocated = false;
}

/* === End of documentation ==================================================================== */

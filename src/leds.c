#include "leds.h"
#include <stdbool.h>
#include <stdio.h>

#define ALL_LEDS_OFF 0x0000
#define FIRST_BIT    0x0001
#define LED_OFFSET   1

#define TerminateIsInvalid(led)                                                                                        \
    if (!IsLedValid(led)) {                                                                                            \
        return;                                                                                                        \
    }

static uint16_t * puerto;
static uint16_t imagen;

static uint16_t LedToBit(int led) {
    return (FIRST_BIT << (led - LED_OFFSET));
}

static void HardwareUpdate(void) {
    *puerto = imagen;
}

static bool IsLedValid(int led) {
    return (led >= 1) && (led <= 16);
}
void LedsInit(uint16_t * direccion) {
    puerto = direccion;
    LedsTurnOffAll();
}

void LedsTurnOnSingle(int led) {
    TerminateIsInvalid(led);
    imagen |= LedToBit(led);
    HardwareUpdate();
}

void LedsTurnOffSingle(int led) {
    TerminateIsInvalid(led);
    imagen &= ~LedToBit(led);
    HardwareUpdate();
}

void LedsTurnOnAll(void) {
    imagen = ~ALL_LEDS_OFF;
    HardwareUpdate();
}

void LedsTurnOffAll(void) {
    imagen = ALL_LEDS_OFF;
    HardwareUpdate();
}

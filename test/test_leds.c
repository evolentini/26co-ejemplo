// - Con todos los leds apagados, al prender un led cualquier se enciende el que corresponde y el resto parmanece
// apagado
// - Con un led prendido, pruebo de apagarlo
// - Recuperar el estado de un led encendido
// - Que se corresponda el orden de la palabra con el numero de led
// - Probar de prender led ya prendidos y de apagar leds apagados
// - Revisar los limites de los argumentos
// - Revisar parámetros fuera de limites

#include "unity.h"
#include "leds.h"

#define TEST_LED        3
#define LED_TO_BIT(led) (1 << (led - 1))

static uint16_t puerto_virtual;

void setUp(void) {
    LedsInit(&puerto_virtual);
}

// - Al configurar la biblioteca por primera los leds deben quedar apagados
void test_todos_los_leds_arrancan_apagados(void) {
    uint16_t puerto_virtual = 0xFFFF;
    LedsInit(&puerto_virtual);
    TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
}

// - Con todos los leds apagados, al prender un led cualquier se enciende el que corresponde y el resto parmanece
// apagado
void test_prender_un_led_individual(void) {
    LedsTurnOnSingle(TEST_LED);
    TEST_ASSERT_EQUAL(LED_TO_BIT(TEST_LED), puerto_virtual);
}

// - Con un led prendido, pruebo de apagarlo
void test_apagar_un_led_individual(void) {
    LedsTurnOnSingle(TEST_LED);
    LedsTurnOffSingle(TEST_LED);
    TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
}

// - Con un led prendido, al prender un segundo led, ambos quedan prendidos y resto apagado
void test_prender_dos_leds_individuales(void) {
    LedsTurnOnSingle(TEST_LED);
    LedsTurnOnSingle(TEST_LED + 2);

    TEST_ASSERT_EQUAL(LED_TO_BIT(TEST_LED) | LED_TO_BIT(TEST_LED + 2), puerto_virtual);
}

// - Con un led prendido, al prender un segundo led, ambos quedan prendidos y resto apagado
void test_prender_dos_leds_y_apagar_uno(void) {
    LedsTurnOnSingle(TEST_LED);
    LedsTurnOnSingle(TEST_LED + 2);
    LedsTurnOffSingle(TEST_LED);

    TEST_ASSERT_EQUAL(LED_TO_BIT(TEST_LED + 2), puerto_virtual);
}

// - Con todos los leds apagados se pueden prender todos los leds
void test_prender_todos_los_leds_simultaneamente(void) {
    LedsTurnOnAll();
    TEST_ASSERT_EQUAL(0xFFFF, puerto_virtual);
}
// - Con todos los leds prendidos se pueden apagar todos los leds
void test_apagar_todos_los_leds_simultaneamente(void) {
    LedsTurnOnAll();
    LedsTurnOffAll();
    TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
}

// - Con todos los leds apagados, al prender un led cualquier se enciende el que corresponde y el resto permanece
// apagado void test_prender_un_led_individual_alternativa(void) {
//     LedsTurnOnSingle(TEST_LED);
//     TEST_ASSERT_TRUE(LedsIsTurnedOn(TEST_LED));
// }

// - Revisar parámetros fuera de limites
// void test_error_en_argumentos_turn_on(void) {
//     RegistrarMensaje_Expect(ALERTA, "LedsTurnOnSingle", 0, "Numero de led invalido (35)");
//     RegistrarMensaje_IgnoreArg_linea();

//     LedsTurnOnSingle(35);
//     TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
// }

// void test_error_en_argumentos_turn_off(void) {
//     RegistrarMensaje_Expect(ALERTA, "LedsTurnOffSingle", 0, "Numero de led invalido (26)");
//     RegistrarMensaje_IgnoreArg_linea();

//     LedsTurnOnAll();
//     LedsTurnOffSingle(26);
//     TEST_ASSERT_EQUAL(0xFFFF, puerto_virtual);
// }

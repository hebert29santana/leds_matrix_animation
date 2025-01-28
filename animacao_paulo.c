#include "animacao_paulo.h"
#include "pico/stdlib.h"

#define NUM_PIXELS 25

void animacao_paulo(double *desenho, uint32_t valor_led, PIO pio, uint sm) {
    // Desenhos que representam os diferentes estados da ampulheta
    double desenho_1[25] = {
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0};

    double desenho_2[25] = {
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        0.0, 0.0, 0.0, 0.0, 1.0,
        0.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0};

    double desenho_3[25] = {
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        0.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0};

    double desenho_4[25] = {
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0};

    double desenho_5[25] = {
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 0.0, 1.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 0.0, 0.0,
        1.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0};

    double desenho_6[25] = {
        0.0, 0.0, 0.0, 0.0, 0.0,
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0};

    double desenho_7[25] = {
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0};

    double desenho_8[25] = {
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0};

    // Exibindo os desenhos em sequência
    desenho_pio(desenho_1, valor_led, pio, sm, 1.0, 1.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_2, valor_led, pio, sm, 1.0, 1.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_3, valor_led, pio, sm, 1.0, 1.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_4, valor_led, pio, sm, 1.0, 1.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_5, valor_led, pio, sm, 1.0, 1.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_6, valor_led, pio, sm, 1.0, 1.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_7, valor_led, pio, sm, 1.0, 1.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_8, valor_led, pio, sm, 1.0, 1.0, 0.0);
    sleep_ms(500);
}

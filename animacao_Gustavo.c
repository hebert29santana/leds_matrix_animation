#include "animacao_Gustavo.h"
#include "pico/stdlib.h"

#define NUM_PIXELS 25

void animacao_Gustavo(double *desenho, uint32_t valor_led, PIO pio, uint sm)
{
    double desenho_1[25] = {
        1.0, 0.0, 1.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        1.0, 0.0, 1.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        1.0, 0.0, 1.0, 0.0, 1.0};

    double desenho_2[25] = {
        0.0, 1.0, 0.0, 1.0, 0.0,
        1.0, 0.0, 1.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        1.0, 0.0, 1.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0,};

    double desenho_3[25] = {
        1.0, 0.0, 1.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        1.0, 0.0, 1.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        1.0, 0.0, 1.0, 0.0, 1.0};

    double desenho_4[25] = {
        0.0, 1.0, 0.0, 1.0, 0.0,
        1.0, 0.0, 1.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        1.0, 0.0, 1.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0,};

    double desenho_5[25] = {
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0};
    
    double desenho_6[25] = {
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0};
    
    double desenho_7[25] = {
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0};
   
    double desenho_8[25] = {
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 1.0, 1.0, 0.0};
   
    double desenho_9[25] = {
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0};
   
    double desenho_10[25] = {
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0};

    double desenho_11[25] = {
        0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0};

    double desenho_12[25] = {
        0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0};

    double desenho_13[25] = {
        0.0, 1.0, 0.0, 1.0, 0.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        0.0, 0.0, 0.0, 0.0, 0.0,
        1.0, 0.0, 0.0, 0.0, 1.0,
        0.0, 1.0, 0.0, 1.0, 0.0};

    desenho_pio(desenho_1, valor_led, pio, sm, 0.0, 1.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_2, valor_led, pio, sm, 0.0, 0.0, 1.0);
    sleep_ms(500);
    desenho_pio(desenho_3, valor_led, pio, sm, 1.0, 0.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_4, valor_led, pio, sm, 1.0, 0.0, 1.0);
    sleep_ms(500);
    desenho_pio(desenho_5, valor_led, pio, sm, 1.0, 0.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_6, valor_led, pio, sm, 1.0, 0.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_7, valor_led, pio, sm, 1.0, 0.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_8, valor_led, pio, sm, 1.0, 0.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_9, valor_led, pio, sm, 1.0, 0.0, 0.0);
    sleep_ms(500);
    desenho_pio(desenho_10, valor_led, pio, sm, 0.0, 0.0, 1.0);
    sleep_ms(500);
    desenho_pio(desenho_11, valor_led, pio, sm, 0.0, 0.0, 1.0);
    sleep_ms(500);
    desenho_pio(desenho_12, valor_led, pio, sm, 0.0, 0.0, 1.0);
    sleep_ms(500);
    desenho_pio(desenho_13, valor_led, pio, sm, 0.0, 0.0, 1.0);
    sleep_ms(500);
    desenho_pio(desenho_12, valor_led, pio, sm, 0.0, 0.0, 1.0);
    sleep_ms(500);
    desenho_pio(desenho_11, valor_led, pio, sm, 0.0, 0.0, 1.0);
    sleep_ms(500);
    desenho_pio(desenho_10, valor_led, pio, sm, 0.0, 0.0, 1.0);
    sleep_ms(500);
}
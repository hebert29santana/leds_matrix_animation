#ifndef ANIMACAO_Gustavo_H
#define ANIMACAO_Gustavo_H

#include <stdint.h>
#include "hardware/pio.h"

void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b);
void animacao_Gustavo(double *desenho, uint32_t valor_led, PIO pio, uint sm);

#endif
#ifndef ANIMACAO_igor_H
#define ANIMACAO_igor_H

#include <stdint.h>
#include "hardware/pio.h"

void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b);
void animacao_igor(double *desenho, uint32_t valor_led, PIO pio, uint sm);

#endif

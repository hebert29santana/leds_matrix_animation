#ifndef animacao_paulo_h
#define animacao_paulo_h

#include <stdint.h>
#include "hardware/pio.h"

// Função para desenhar padrões nos LEDs
void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b);

// Função para animar a ampulheta
void animacao_paulo(double *desenho, uint32_t valor_led, PIO pio, uint sm);

#endif // animacao_paulo_h
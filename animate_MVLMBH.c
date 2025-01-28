/*
    Animação Matriz de Leds RGB
    Maria Valentina da Luz Mattos Baracat Habib
    TIC370101020
    Grupo 7
    Subgrupo 6
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include <hardware/pio.h>
#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "auxiliar.pio.h"


// Configurações
#define COUNT 25                // Número de LEDs (matriz 5x5)
#define PINLED 7                   // Pino GPIO conectado aos LEDs
#define PINBUZZER  21               // Pino GPIO conectado ao buzzer

struct pixel_t {
    uint8_t G, R, B;                // Componentes de cor: Verde, Vermelho, Azul
};

typedef struct pixel_t pixel_t;
pixel_t led[COUNT];
PIO nppio;
uint s_m;

// Notas musicais em Hz
#define NOTEC4  261
#define NOTEE4  329
#define NOTEG4  392
#define NOTEC5  523

// Inicialização dos LEDs da Matriz 5x5
void Init(uint pin) {
    uint offset = pio_add_program(pio0, &auxiliar_program);
    nppio = pio0;
    s_m = pio_claim_unused_sm(nppio, false);
    if (s_m < 0) {
        nppio = pio1;
        s_m = pio_claim_unused_sm(nppio, true);
    }
    auxiliar_program_init(nppio, s_m, offset, pin, 800000.f);

    for (uint i = 0; i < COUNT; ++i) {
        led[i].R = 0;
        led[i].G = 0;
        led[i].B = 0;
    }
}

// Define um LED com cores específicas e sua intensidade
void SETColor(const uint index, const uint8_t r, const uint8_t g, const uint8_t b) {
    led[index].R = r * 0.7;
    led[index].G = g * 0.7; // Só pra Lembrar, era 0.3
    led[index].B = b * 0.7;
}

// Limpa todos os LEDs
void Limpa() {
    for (uint i = 0; i < COUNT; ++i)
        SETColor(i, 0, 0, 0);
}

// Atualiza o hardware dos LEDs
void UpdateHard() {
    for (uint i = 0; i < COUNT; ++i) {
        pio_sm_put_blocking(nppio, s_m, led[i].G);
        pio_sm_put_blocking(nppio, s_m, led[i].R);
        pio_sm_put_blocking(nppio, s_m, led[i].B);
    }
}

// Toca uma nota no buzzer ainda não funciona direito
void Note(uint16_t frequency, uint32_t duration_ms) {
    gpio_set_function(PINBUZZER, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PINBUZZER);
    uint32_t wrap = clock_get_hz(clk_sys) / frequency - 1;
    pwm_set_wrap(slice_num, wrap);
    pwm_set_gpio_level(PINBUZZER, wrap / 2);  // 50% duty cycle
    pwm_set_enabled(slice_num, true);
    sleep_ms(duration_ms);
    pwm_set_enabled(slice_num, false);
}

// Toca uma melodia simples
void Melody() {
    Note(NOTEC4, 300);
    Note(NOTEE4, 300);
    Note(NOTEG4, 300);
    Note(NOTEC5, 500);
    sleep_ms(200);
}

void frame1v1() {

    Limpa();
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v2() {

    Limpa();
    SETColor(0, 0, 255, 0);
    SETColor(1, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v3() {

    Limpa();
    SETColor(0, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(2, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v4() {

    Limpa();
    SETColor(3, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v5() {

    Limpa();
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v6() {

    Limpa();
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v7() {

    Limpa();
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v8() {

    Limpa();
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v9() {

    Limpa();
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v10() {

    Limpa();
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}



void frame1v11() {

    Limpa();
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v12() {

    Limpa();
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v13() {

    Limpa();
    SETColor(12, 0, 255, 0);
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}


void frame1v14() {

    Limpa();
    SETColor(13, 0, 255, 0);
    SETColor(12, 0, 255, 0);
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v15() {

    Limpa();
    SETColor(14, 0, 255, 0);
    SETColor(13, 0, 255, 0);
    SETColor(12, 0, 255, 0);
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}


void frame1v16() {

    Limpa();
    SETColor(15, 0, 255, 0);
    SETColor(14, 0, 255, 0);
    SETColor(13, 0, 255, 0);
    SETColor(12, 0, 255, 0);
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v17() {

    Limpa();
    SETColor(16, 0, 255, 0);
    SETColor(15, 0, 255, 0);
    SETColor(14, 0, 255, 0);
    SETColor(13, 0, 255, 0);
    SETColor(12, 0, 255, 0);
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v18() {

    Limpa();
    SETColor(17, 0, 255, 0);
    SETColor(16, 0, 255, 0);
    SETColor(15, 0, 255, 0);
    SETColor(14, 0, 255, 0);
    SETColor(13, 0, 255, 0);
    SETColor(12, 0, 255, 0);
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v19() {

    Limpa();
    SETColor(18, 0, 255, 0);
    SETColor(17, 0, 255, 0);
    SETColor(16, 0, 255, 0);
    SETColor(15, 0, 255, 0);
    SETColor(14, 0, 255, 0);
    SETColor(13, 0, 255, 0);
    SETColor(12, 0, 255, 0);
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v20() {

    Limpa();
    SETColor(19, 0, 255, 0);
    SETColor(18, 0, 255, 0);
    SETColor(17, 0, 255, 0);
    SETColor(16, 0, 255, 0);
    SETColor(15, 0, 255, 0);
    SETColor(14, 0, 255, 0);
    SETColor(13, 0, 255, 0);
    SETColor(12, 0, 255, 0);
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v21() {

    Limpa();
    SETColor(20, 0, 255, 0);
    SETColor(19, 0, 255, 0);
    SETColor(18, 0, 255, 0);
    SETColor(17, 0, 255, 0);
    SETColor(16, 0, 255, 0);
    SETColor(15, 0, 255, 0);
    SETColor(14, 0, 255, 0);
    SETColor(13, 0, 255, 0);
    SETColor(12, 0, 255, 0);
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(70);
}

void frame1v22() {

    Limpa();
    SETColor(21, 0, 255, 0);
    SETColor(20, 0, 255, 0);
    SETColor(19, 0, 255, 0);
    SETColor(18, 0, 255, 0);
    SETColor(17, 0, 255, 0);
    SETColor(16, 0, 255, 0);
    SETColor(15, 0, 255, 0);
    SETColor(14, 0, 255, 0);
    SETColor(13, 0, 255, 0);
    SETColor(12, 0, 255, 0);
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(100);
}

void frame1v23() {

    Limpa();
    SETColor(22, 0, 255, 0);
    SETColor(21, 0, 255, 0);
    SETColor(20, 0, 255, 0);
    SETColor(19, 0, 255, 0);
    SETColor(18, 0, 255, 0);
    SETColor(17, 0, 255, 0);
    SETColor(16, 0, 255, 0);
    SETColor(15, 0, 255, 0);
    SETColor(14, 0, 255, 0);
    SETColor(13, 0, 255, 0);
    SETColor(12, 0, 255, 0);
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(130);
}

void frame1v24() {

    Limpa();
    SETColor(23, 0, 255, 0);
    SETColor(22, 0, 255, 0);
    SETColor(21, 0, 255, 0);
    SETColor(20, 0, 255, 0);
    SETColor(19, 0, 255, 0);
    SETColor(18, 0, 255, 0);
    SETColor(17, 0, 255, 0);
    SETColor(16, 0, 255, 0);
    SETColor(15, 0, 255, 0);
    SETColor(14, 0, 255, 0);
    SETColor(13, 0, 255, 0);
    SETColor(12, 0, 255, 0);
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(160);
}

void frame1v25() {

    Limpa();

    SETColor(24, 0, 255, 0);
    SETColor(23, 0, 255, 0);
    SETColor(22, 0, 255, 0);
    SETColor(21, 0, 255, 0);
    SETColor(20, 0, 255, 0);
    SETColor(19, 0, 255, 0);
    SETColor(18, 0, 255, 0);
    SETColor(17, 0, 255, 0);
    SETColor(16, 0, 255, 0);
    SETColor(15, 0, 255, 0);
    SETColor(14, 0, 255, 0);
    SETColor(13, 0, 255, 0);
    SETColor(12, 0, 255, 0);
    SETColor(11, 0, 255, 0);
    SETColor(10, 0, 255, 0);
    SETColor(9, 0, 255, 0);
    SETColor(8, 0, 255, 0);
    SETColor(7, 0, 255, 0);
    SETColor(6, 0, 255, 0);
    SETColor(3, 0, 255, 0);
    SETColor(4, 0, 255, 0);
    SETColor(2, 0, 255, 0);
    SETColor(5, 0, 255, 0);
    SETColor(1, 0, 255, 0);
    SETColor(0, 0, 255, 0);

    UpdateHard();
    sleep_ms(200);
}

void frame1v26() {

    Limpa();

    SETColor(24, 255, 0, 255);
    SETColor(23, 255, 0, 255);
    SETColor(22, 255, 0, 255);
    SETColor(21, 255, 0, 255);
    SETColor(20, 255, 0, 255);
    SETColor(19, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(16, 255, 0, 255);
    SETColor(15, 255, 0, 255);
    SETColor(14, 255, 0, 255);
    SETColor(13, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(9, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(3, 255, 0, 255);
    SETColor(4, 255, 0, 255);
    SETColor(2, 255, 0, 255);
    SETColor(5, 255, 0, 255);
    SETColor(1, 255, 0, 255);
    SETColor(0, 255, 0, 255);

    UpdateHard();
    sleep_ms(400);
}



void frame1() {

    Limpa();
    SETColor(9, 255, 0, 255);
    SETColor(10, 255, 0, 255); 
    SETColor(19, 255, 0, 255);

    UpdateHard();
    sleep_ms(600);
}

void frame2() {
    
    Limpa();

    SETColor(8, 255, 0, 255); 
    SETColor(9, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(18, 255, 0, 255); 
    SETColor(19, 255, 0, 255);

    UpdateHard();
    sleep_ms(600);
}

void frame3() {
    
    Limpa();

    SETColor(7, 255, 0, 255); 
    SETColor(8, 255, 0, 255);
    SETColor(9, 255, 0, 255);
    SETColor(10, 255, 0, 255); 
    SETColor(12, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(19, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame4() {
    
    Limpa();

    SETColor(6, 255, 0, 255); 
    SETColor(7, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(11, 255, 0,255); 
    SETColor(13, 255, 0, 255);
    SETColor(16, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(18, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame5() {
    
    Limpa();

    SETColor(5, 255, 0, 255); 
    SETColor(6, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(12, 255, 0, 255); 
    SETColor(14, 255, 0, 255);
    SETColor(15, 255, 0, 255);
    SETColor(16, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(9, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(19, 255, 0, 255);




    UpdateHard();
    sleep_ms(600);

}

void frame6() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(16, 255, 0, 255);
    SETColor(13, 255, 0, 255);
    SETColor(6, 255, 0, 255); 
    SETColor(5, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(9, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame7() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(14, 255, 0, 255);
    SETColor(5, 255, 0, 255);
    SETColor(12, 255, 0, 255); 
    SETColor(7, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(9, 255, 0, 255);

    


    UpdateHard();
    sleep_ms(600);

}

void frame8() {
    
    Limpa();

    SETColor(13, 255, 0, 255); 
    SETColor(16, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    


    UpdateHard();
    sleep_ms(600);

}

void frame9() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(14, 255, 0, 255);
    SETColor(5, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(9, 255, 0, 255);
  


    UpdateHard();
    sleep_ms(600);

}

void frame10() {
    
    Limpa();

    SETColor(5, 255, 0, 255); 
    SETColor(6, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(19, 255, 0, 255);
    SETColor(11, 255, 0, 255);

    UpdateHard();
    sleep_ms(600);

}

void frame11() {
    
    Limpa();

    SETColor(5, 255, 0, 255); 
    SETColor(7, 255, 0, 255); 
    SETColor(12, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(9, 255, 0, 255);
 

    UpdateHard();
    sleep_ms(600);

}


void frame12() {
    
    Limpa();
    SETColor(13, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(8, 255, 0, 255);

    UpdateHard();
    sleep_ms(600);

}

void frame13() {
    
    Limpa();

    SETColor(5, 255, 0, 255); 
    SETColor(14, 255, 0, 255);
    SETColor(13, 255, 0, 255);
    SETColor(16, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(7, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame14() {
    
    Limpa();

    SETColor(14, 255, 0, 255); 
    SETColor(15, 255, 0, 255);
    SETColor(13, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(19, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(9, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame15() {
    
    Limpa();

    SETColor(14, 255, 0, 255); 
    SETColor(5, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(19, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame16() {
    
    Limpa();

    SETColor(7, 255, 0, 255); 
    SETColor(12, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(10, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame17() {
    
    Limpa();

    SETColor(6, 255, 0, 255); 
    SETColor(13, 255, 0, 255);
    SETColor(16, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(19, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}


void frame18() {
    
    Limpa();

    SETColor(5, 255, 0, 255); 
    SETColor(14, 255, 0, 255);
    SETColor(15, 255, 0, 255);
    SETColor(16, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(19, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(9, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame19() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(13, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(8, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame20() {
    
    Limpa();

    SETColor(14, 255, 0, 255); 
    SETColor(16, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(19, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(9, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame21() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(16, 255, 0, 255);
    SETColor(13, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(9, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame22() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(14, 255, 0, 255);
    SETColor(5, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(9, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(19, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame23() {
    
    Limpa();

    SETColor(16, 255, 0, 255); 
    SETColor(13, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(18, 255, 0, 255);

    UpdateHard();
    sleep_ms(600);

}

void frame24() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(14, 255, 0, 255);
    SETColor(5, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(19, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(9, 255, 0, 255);

    UpdateHard();
    sleep_ms(600);

}

void frame25() {
    
    Limpa();

    SETColor(5, 255, 0, 255); 
    SETColor(6, 255, 0, 255);
    SETColor(13, 255, 0, 255);
    SETColor(16, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(10, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame26() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(14, 255, 0, 255);
    SETColor(5, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(9, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame27() {
    
    Limpa();

    SETColor(16, 255, 0, 255); 
    SETColor(13, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(19, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame28() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(14, 255, 0, 255);
    SETColor(5, 255, 0, 255);
    SETColor(13, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(18, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame29() {
    
    Limpa();

    SETColor(14, 255, 0, 255); 
    SETColor(6, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(19, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(9, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}



void frame30() {
    
    Limpa();

    SETColor(5, 255, 0, 255); 
    SETColor(13, 255, 0, 255);
    SETColor(16, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(19, 255, 0, 255);
    SETColor(9, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame31() {
    
    Limpa();

    SETColor(14, 255, 0, 255); 
    SETColor(15, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(7, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame32() {
    
    Limpa();

    SETColor(16, 255, 0, 255); 
    SETColor(13, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(11, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame33() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(14, 255, 0, 255);
    SETColor(5, 255, 0, 255);
    SETColor(16, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(19, 255, 0, 255);
    SETColor(10, 255, 0, 255);
    SETColor(9, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame34() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(13, 255, 0, 255);
    SETColor(5, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(19, 255, 0, 255);
    SETColor(9, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame35() {
    
    Limpa();

    SETColor(14, 255, 0, 255); 
    SETColor(17, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(8, 255, 0, 255);
    SETColor(19, 255, 0, 255);
    SETColor(9, 255, 0, 255);
    SETColor(10, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame36() {
    
    Limpa();

    SETColor(16, 255, 0, 255); 
    SETColor(13, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(11, 255, 0, 255);
    SETColor(8, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}

void frame37() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(14, 255, 0, 255);
    SETColor(5, 255, 0, 255);
    SETColor(16, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(12, 255, 0, 255);
    SETColor(7, 255, 0, 255);
    SETColor(20, 255, 0, 255);
    SETColor(19, 255, 0, 255);
    SETColor(9, 255, 0, 255);



    UpdateHard();
    sleep_ms(600);

}


void frame38() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(16, 255, 0, 255);
    SETColor(13, 255, 0, 255);
    SETColor(5, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(21, 255, 0, 255);
    SETColor(18, 255, 0, 255);
    SETColor(8, 255, 0, 255);


    UpdateHard();
    sleep_ms(600);

}


void frame39() {
    
    Limpa();

    SETColor(15, 255, 0, 255); 
    SETColor(14, 255, 0, 255);
    SETColor(5, 255, 0, 255);
    SETColor(22, 255, 0, 255);
    SETColor(17, 255, 0, 255);
    SETColor(7, 255, 0, 255);

    UpdateHard();
    sleep_ms(600);

}


void frame40() {
    
    Limpa();

    SETColor(23, 255, 0, 255); 
    SETColor(16, 255, 0, 255);
    SETColor(6, 255, 0, 255);
    SETColor(19, 255, 0, 0);

    UpdateHard();
    sleep_ms(600);

}

void frame41() {
    
    Limpa();

    SETColor(24, 255, 0, 255); 
    SETColor(15, 255, 0, 255);
    SETColor(5, 255, 0, 255);
    SETColor(18, 255, 0, 0);
    SETColor(20, 255, 0, 0);
    SETColor(10, 255, 0, 0);

    UpdateHard();
    sleep_ms(600);

}



void frame42() {
    
    Limpa();

    SETColor(21, 255, 0, 0); 
    SETColor(17, 255, 0, 0); 
    SETColor(11, 255, 0, 0); 
    SETColor(9, 255, 0, 0); 
    SETColor(19, 255, 0, 0); 


    UpdateHard();
    sleep_ms(600);

}

void frame43() {
    
    Limpa();

    SETColor(22, 255, 0, 0); 
    SETColor(16, 255, 0, 0); 
    SETColor(12, 255, 0, 0); 
    SETColor(8, 255, 0, 0); 
    SETColor(18, 255, 0, 0); 
    SETColor(10, 255, 0, 0); 
    SETColor(20, 255, 0, 0); 


    UpdateHard();
    sleep_ms(400);

}

void frame44() {
    
    Limpa();

    SETColor(15, 255, 0, 0); 
    SETColor(23, 255, 0, 0); 
    SETColor(13, 255, 0, 0); 
    SETColor(17, 255, 0, 0); 
    SETColor(7, 255, 0, 0); 
    SETColor(21, 255, 0, 0); 
    SETColor(19, 255, 0, 0); 
    SETColor(11, 255, 0, 0); 

    UpdateHard();
    sleep_ms(400);

}

void frame45() {
    
    Limpa();

    SETColor(15, 0, 255, 0); 
    SETColor(23, 0, 255, 0); 
    SETColor(13, 0, 255, 0); 
    SETColor(17, 0, 255, 0); 
    SETColor(7, 0, 255, 0); 
    SETColor(21, 0, 255, 0); 
    SETColor(19, 0, 255, 0); 
    SETColor(11, 0, 255, 0); 

    UpdateHard();
    sleep_ms(400);

}

void frame46() {
    
    Limpa();

    SETColor(15, 0, 0, 255); 
    SETColor(23, 0, 0, 255); 
    SETColor(13, 0, 0, 255); 
    SETColor(17, 0, 0, 255); 
    SETColor(7, 0, 0, 255); 
    SETColor(21, 0, 0, 255); 
    SETColor(19, 0, 0, 255); 
    SETColor(11, 0, 0, 255); 

    UpdateHard();
    sleep_ms(400);

}

void frame47() {
    
    Limpa();

    SETColor(15, 255, 0, 0); 
    SETColor(23, 255, 0, 0); 
    SETColor(13, 255, 0, 0); 
    SETColor(17, 255, 0, 0); 
    SETColor(7, 255, 0, 0); 
    SETColor(21, 255, 0, 0); 
    SETColor(19, 255, 0, 0); 
    SETColor(11, 255, 0, 0); 

    UpdateHard();
    sleep_ms(400);

}

void frame48() {
    
    Limpa();

    SETColor(15, 0, 255, 0); 
    SETColor(23, 0, 255, 0); 
    SETColor(13, 0, 255, 0); 
    SETColor(17, 0, 255, 0); 
    SETColor(7, 0, 255, 0); 
    SETColor(21, 0, 255, 0); 
    SETColor(19, 0, 255, 0); 
    SETColor(11, 0, 255, 0); 

    UpdateHard();
    sleep_ms(400);

}

void frame49() {
    
    Limpa();

    SETColor(15, 0, 0, 255); 
    SETColor(23, 0, 0, 255); 
    SETColor(13, 0, 0, 255); 
    SETColor(17, 0, 0, 255); 
    SETColor(7, 0, 0, 255); 
    SETColor(21, 0, 0, 255); 
    SETColor(19, 0, 0, 255); 
    SETColor(11, 0, 0, 255); 

    UpdateHard();
    sleep_ms(400);

}

void frame50() {
    
    Limpa();

    SETColor(15, 255, 0, 0); 
    SETColor(23, 255, 0, 0); 
    SETColor(13, 255, 0, 0); 
    SETColor(17, 255, 0, 0); 
    SETColor(7, 255, 0, 0); 
    SETColor(21, 255, 0, 0); 
    SETColor(19, 255, 0, 0); 
    SETColor(11, 255, 0, 0); 

    UpdateHard();
    sleep_ms(1000);

}






// Animação principal
// DO FRAME 1V1 AO FRAME1V26 É A ANIMAÇÃO DE CARREGAMENTO. APOS ISSO, "OLA MUNDO! <3"

void animateMaria() {
    frame1v1();
    frame1v2();
    frame1v3();
    frame1v4();
    frame1v5();
    frame1v6();
    frame1v7();
    frame1v8();
    frame1v9();
    frame1v10();
    frame1v11();
    frame1v12();
    frame1v13();
    frame1v14();
    frame1v15();
    frame1v16();
    frame1v17();
    frame1v18();
    frame1v19();
    frame1v20();
    frame1v21();
    frame1v22();
    frame1v21();
    frame1v24();
    frame1v25();
    frame1v26();
    frame1();
    frame2();
    frame3();
    frame4();
    frame5();
    frame6();
    frame7();
    frame8();
    frame9();
    frame10();
    frame11();
    frame12();
    frame13();
    frame14();
    frame15();
    frame16();
    frame17();
    frame18();
    frame19();
    frame20();
    frame21();
    frame22();
    frame23();
    frame24();
    frame25();
    frame26();
    frame27();
    frame28();
    frame29();
    frame30();
    frame31();
    frame32();
    frame33();
    frame34();
    frame35();
    frame36();
    frame37();
    frame38();
    frame39();
    frame40();
    frame41();
    frame42();
    frame43();
    frame44();
    frame45();
    frame46();
    frame47();
    frame48();
    frame49();
    frame50();




    Limpa();

}

int animate_MVLMBH() {
    stdio_init_all();
    Init(PINLED);
    gpio_init(PINBUZZER);
    gpio_set_dir(PINBUZZER, GPIO_OUT);

    while (true) {
        animateMaria();              
        Melody();           // Tocar melodia
        sleep_ms(2000);         // Pausa antes de repetir
    }
}

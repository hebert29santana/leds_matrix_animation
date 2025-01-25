/*
    Animação Matriz de Leds RGB
    Hebert Costa Vaz Santana
    TIC370101235
    Grupo 7
    Subgrupo 6
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include <hardware/pio.h>
#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "ws2818b.pio.h"

// Configurações
#define LED_COUNT 25                // Número de LEDs (matriz 5x5)
#define LED_PIN 7                   // Pino GPIO conectado aos LEDs
#define BUZZER_PIN 21               // Pino GPIO conectado ao buzzer

struct pixel_t {
    uint8_t G, R, B;                // Componentes de cor: Verde, Vermelho, Azul
};

typedef struct pixel_t pixel_t;
pixel_t leds[LED_COUNT];
PIO np_pio;
uint sm;

// Notas musicais em Hz
#define NOTE_C4  261
#define NOTE_E4  329
#define NOTE_G4  392
#define NOTE_C5  523

// Inicialização dos LEDs da Matriz 5x5
void ledInit(uint pin) {
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;
    sm = pio_claim_unused_sm(np_pio, false);
    if (sm < 0) {
        np_pio = pio1;
        sm = pio_claim_unused_sm(np_pio, true);
    }
    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);

    for (uint i = 0; i < LED_COUNT; ++i) {
        leds[i].R = 0;
        leds[i].G = 0;
        leds[i].B = 0;
    }
}

// Define um LED com cores específicas e sua intensidade
void ledSETColor(const uint index, const uint8_t r, const uint8_t g, const uint8_t b) {
    leds[index].R = r * 0.7;
    leds[index].G = g * 0.7; // Só pra Lembrar, era 0.3
    leds[index].B = b * 0.7;
}

// Limpa todos os LEDs
void ledLimpa() {
    for (uint i = 0; i < LED_COUNT; ++i)
        ledSETColor(i, 0, 0, 0);
}

// Atualiza o hardware dos LEDs
void ledUpdateHard() {
    for (uint i = 0; i < LED_COUNT; ++i) {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
}

// Toca uma nota no buzzer ainda não funciona direito
void playNote(uint16_t frequency, uint32_t duration_ms) {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    uint32_t wrap = clock_get_hz(clk_sys) / frequency - 1;
    pwm_set_wrap(slice_num, wrap);
    pwm_set_gpio_level(BUZZER_PIN, wrap / 2);  // 50% duty cycle
    pwm_set_enabled(slice_num, true);
    sleep_ms(duration_ms);
    pwm_set_enabled(slice_num, false);
}

// Toca uma melodia simples
void playMelody() {
    playNote(NOTE_C4, 300);
    playNote(NOTE_E4, 300);
    playNote(NOTE_G4, 300);
    playNote(NOTE_C5, 500);
    sleep_ms(200);
}

// Montar as Letras das Iniciais do meu nome "HCVS"

// Letra H é acesa com a cor Vermelha
void letraH() {
    ledLimpa();
    ledSETColor(1, 255, 0, 0); 
    ledSETColor(8, 255, 0, 0);
    ledSETColor(11, 255, 0, 0);
    ledSETColor(18, 255, 0, 0);
    ledSETColor(21, 255, 0, 0);
    ledSETColor(12, 255, 0, 0); //Traço do meio no H
    ledSETColor(3, 255, 0, 0);
    ledSETColor(6, 255, 0, 0);
    ledSETColor(13, 255, 0, 0); 
    ledSETColor(16, 255, 0, 0); 
    ledSETColor(23, 255, 0, 0); 
    ledUpdateHard();
    sleep_ms(1000);
}

// Letra C é acesa com a cor Verde
void letraC() {
    ledLimpa();
    ledSETColor(1, 0, 255, 0); 
    ledSETColor(2, 0, 255, 0);
    ledSETColor(3, 0, 255, 0); 
    ledSETColor(6, 0, 255, 0);
    ledSETColor(13, 0, 255, 0);
    ledSETColor(16, 0, 255, 0);
    ledSETColor(23, 0, 255, 0);
    ledSETColor(22, 0, 255, 0);
    ledSETColor(21, 0, 255, 0);
    ledUpdateHard();
    sleep_ms(1000);
}

// Letra V é acesa com a cor Azul
void letraV() {
    ledLimpa();
    ledSETColor(23, 0, 0, 255); 
    ledSETColor(16, 0, 0, 255);
    ledSETColor(13, 0, 0, 255); 
    ledSETColor(6, 0, 0, 255);
    ledSETColor(2, 0, 0, 255);
    ledSETColor(8, 0, 0, 255);
    ledSETColor(11, 0, 0, 255);
    ledSETColor(18, 0, 0, 255);
    ledSETColor(21, 0, 0, 255);
    ledUpdateHard();
    sleep_ms(1000);
}

// Letra S é acesa com a cor Amarela
void letraS() {
    ledLimpa();
    ledSETColor(1, 255, 255, 0); 
    ledSETColor(2, 255, 255, 0);
    ledSETColor(3, 255, 255, 0);
    ledSETColor(8, 255, 255, 0);
    ledSETColor(16, 255, 255, 0);
    ledSETColor(13, 255, 255, 0);
    ledSETColor(12, 255, 255, 0);
    ledSETColor(11, 255, 255, 0);
    ledSETColor(23, 255, 255, 0);
    ledSETColor(22, 255, 255, 0);
    ledSETColor(21, 255, 255, 0);
    ledUpdateHard();
    sleep_ms(1000);
}

void flagBrasil() {
    // Loop para fazer o bandeira piscar 3 vezes
    for (int i = 0; i < 3; i++) { 
        // Desenhando a bandeira
        // Os leds vão ascender em Verde, Amarelo e Azul
        ledLimpa();
        ledSETColor(0, 0, 255, 0); 
        ledSETColor(1, 0, 255, 0);
        ledSETColor(2, 0, 255, 0);
        ledSETColor(3, 0, 255, 0);
        ledSETColor(4, 0, 255, 0);
        ledSETColor(5, 0, 255, 0);
        ledSETColor(6, 0, 255, 0);
        ledSETColor(7, 255, 255, 0); // Amarelo, Losango
        ledSETColor(8, 0, 255, 0);
        ledSETColor(9, 0, 255, 0);
        ledSETColor(10, 0, 255, 0); 
        ledSETColor(11, 255, 255, 0); // Amarelo, Losango
        ledSETColor(12, 0, 0, 255); // Azul, meio da bandeira
        ledSETColor(13, 255, 255, 0); // Amarelo, Losango
        ledSETColor(14, 0, 255, 0);
        ledSETColor(15, 0, 255, 0);
        ledSETColor(16, 0, 255, 0);
        ledSETColor(17, 255, 255, 0); // Amarelo, Losango
        ledSETColor(18, 0, 255, 0);
        ledSETColor(19, 0, 255, 0);
        ledSETColor(20, 0, 255, 0);
        ledSETColor(21, 0, 255, 0);
        ledSETColor(22, 0, 255, 0);
        ledSETColor(23, 0, 255, 0);
        ledSETColor(24, 0, 255, 0);
        ledUpdateHard();
        sleep_ms(700);  // Bandeira fica visível por 700 ms

        // Apaga todos os LEDs
        ledLimpa();
        ledUpdateHard();
        sleep_ms(200);  // Bandeira apaga por 200 ms
    }
}

// Exibe bandeira arco-íris, linha por linha
void rainbowFlag() {
    uint8_t colors[5][3] = {
        {255, 0, 0},   // Vermelho
        {255, 165, 0}, // Laranja
        {255, 255, 0}, // Amarelo
        {0, 255, 0},   // Verde
        {0, 0, 255}    // Azul
    };

    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            // Calcula o índice e acende os LEDs da linha atual
            ledSETColor(row * 5 + col, colors[row][0], colors[row][1], colors[row][2]);
        }
        ledUpdateHard();         // Atualiza os LEDs da linha atual
        sleep_ms(500);     // Espera 500 ms antes de passar para a próxima linha
    }

    sleep_ms(1000);         // Mantém a bandeira acesa por 2 segundos
}


// Função para gerar uma onda de arco-íris
void rainbowWave() {
    for (int t = 0; t < LED_COUNT; t++) {
        for (int i = 0; i < LED_COUNT; i++) {
            uint8_t r = (i + t) % 3 == 0 ? 255 : 0; // Vermelho em padrão cíclico
            uint8_t g = (i + t) % 3 == 1 ? 255 : 0; // Verde em padrão cíclico
            uint8_t b = (i + t) % 3 == 2 ? 255 : 0; // Azul em padrão cíclico
            ledSETColor(i, r, g, b);
        }
        ledUpdateHard();
        sleep_ms(100);
    }
}

// Animação principal
void animate() {
    rainbowFlag();
    letraH();
    letraC();
    letraV();
    letraS();
    flagBrasil();
    rainbowWave();
    ledLimpa();
}

int animate_HCVS() {
    stdio_init_all();
    ledInit(LED_PIN);
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    while (true) {
        animate();              // Exibir HCVS seguido da bandeira
        playMelody();           // Tocar melodia
        sleep_ms(2000);         // Pausa antes de repetir
    }
}

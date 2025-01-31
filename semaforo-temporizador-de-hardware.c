#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include "pico/stdlib.h" // Inclui a biblioteca padrão para funcionalidades básicas
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware

// Define o LEDs de saída
#define GPIO_RED_LED 11
#define GPIO_YELLOW_LED 12
#define GPIO_GREEN_LED 13

// Conexão dos pinos GPIO
const uint8_t GPIOs[] = {GPIO_RED_LED, GPIO_YELLOW_LED, GPIO_GREEN_LED};

// Varialvel Global
int cont = 1, ms = 3000;

// Protótipo de Função
void inicializar_led();
bool repeating_timer_callback(struct repeating_timer *t);

// Declaração de uma estrutura de temporizador de repetição
struct repeating_timer timer;

int main() {
  stdio_init_all();
  inicializar_led();

  // Configura o temporizador para chamar a função de callback a cada 3 segundo
  add_repeating_timer_ms(ms, repeating_timer_callback, NULL, &timer);

  while(1){
    // Imprimir algum tipo de informação a cada segundo (1.000 ms)
    printf("1 segundo passou\n");
    // Pausa de 1000 ms para reduzir o uso da CPU.
    sleep_ms(1000);
  }
}

// Função para inicializar saídas dos LEDs
void inicializar_led(){
   for (int i = 0; i < 3; i++){
    gpio_init(GPIOs[i]);
    gpio_set_dir(GPIOs[i], GPIO_OUT);
  }
}

// Função de callback que será chamada repetidamente pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {

    if(cont == 1 || cont == 2){ // 1 ligado, 2 desligado
      gpio_put(GPIO_RED_LED, !gpio_get(GPIO_RED_LED));
    }else if(cont == 3 || cont == 4){ // 3 ligado, 4 desligado
      gpio_put(GPIO_YELLOW_LED, !gpio_get(GPIO_YELLOW_LED));
    }else if(cont == 5 || cont == 6){ // 5 ligado, 6 desligado
      gpio_put(GPIO_GREEN_LED, !gpio_get(GPIO_GREEN_LED));
    }

    // Se chegou no fim do ciclo, reinicia
    if(cont == 6){
      cont = 0;
    }

    //Incremento
    cont++;

    // Alterna entre 3s (3000ms) ligado e 1s (100ms) desligado
    (cont % 2) == 1 ? (ms = 100) : (ms = 3000);
    
    // Reinicia o timer com o novo intervalo
    add_repeating_timer_ms(ms, repeating_timer_callback, NULL, &timer);
    
    // Retorna false para parar o timer anterior
    return false;
}

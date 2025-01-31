# 🚦 Semáforo usando temporizador de hardware
Este projeto demonstra como usar um Raspberry Pi Pico W para fazer um semáforo de LEDs usando
temporizador de hardware que permiter o LED fica ligado por de 3 segundos e desligador por 1 segundo piscando os LEDs.
## Funcionalidade:
- O acionamento dos LEDs (sinais do semáforo) deve iniciar na cor vermelha 🔴, alterando para amarela 🟡 e, em seguida, verde 🟢.
## Requisitos de Hardware:
- Microcontrolador Raspberry Pi Pico W
- 03 LEDs (vermelho, amarelo e verde)
- 03 Resistores de 330 Ω
## Requisitos de Software:
- Instalar o Visual Studio Code
- Instalar a extensão Wokwi no VSCode
- Instalar os pacotes do Pico SDK
## Pinos GPIO dos LEDs
O sistema utiliza três LEDs conectados aos seguintes pinos GPIO do Raspberry Pi Pico W:
- LED Vermelho: GPIO 11
- LED Amarelo: GPIO 12
- LED Verde: GPIO 13
## Explicação do Código:
- **stdio_init_all()**: Inicializar comunicação padrão
- **inicializar_led()**: Inicializar as configurações dos pinos dos LEDs como saída
- **add_repeating_timer_ms(ms, repeating_timer_callback, NULL, &timer)**: Configura o temporizador para chamar a função de callback
- **repeating_timer_callback(struct repeating_timer *t)**: Função de callback que será chamada repetidamente pelo temporizador
## Produção do vídeo
https://github.com/user-attachments/assets/144a2069-f856-4354-b37d-664d9361ff16
## Imagem do Projeto
![image](https://github.com/user-attachments/assets/66adc950-a6c9-4b6b-a5cd-0b45652ee1d9)



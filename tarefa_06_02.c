#include <stdio.h> // Biblioteca padrão da linguagem C
#include "pico/stdlib.h" // Subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" // Biblioteca para controlar o hardware de PWM

#define SERVO 22 // Define o pino GPIO 22 para o servomotor
const uint16_t WRAP_PERIOD = 20000; // Período de 20ms (50Hz) para PWM do servomotor
const float PWM_DIVISER = 125.0; // Divisor do clock para o PWM (isso ajusta para 50Hz)
const uint16_t SERVO_180 = 2400; // 180 graus (2400µs)
const uint16_t SERVO_90 = 1470; // 90 graus (1470µs)
const uint16_t SERVO_0 = 500; // 0 graus (500µs)

// Função para configurar o módulo PWM
void pwm_setup() {
    gpio_set_function(SERVO, GPIO_FUNC_PWM); // Habilita o pino GPIO 22 como PWM

    uint slice_servo = pwm_gpio_to_slice_num(SERVO); // Obtém o canal PWM da GPIO

    pwm_set_clkdiv(slice_servo, PWM_DIVISER); // Define o divisor de clock do PWM para 50Hz

    pwm_set_wrap(slice_servo, WRAP_PERIOD); // Define o valor de wrap para 20ms

    pwm_set_gpio_level(SERVO, 0); // Inicializa o ciclo de trabalho (duty cycle) do PWM

    pwm_set_enabled(slice_servo, true); // Habilita o PWM no slice do servomotor
}

int main() {
    stdio_init_all(); // Inicializa a comunicação padrão do sistema
    pwm_setup(); // Configura o PWM

    // Definir o ciclo de trabalho do servomotor para 180 graus (2400µs)
    pwm_set_gpio_level(SERVO, SERVO_180);
    printf("Posicionando o servomotor a 180 graus (2400µs)\n");
    sleep_ms(5000); // Aguarda 5 segundos nesta posição

    // Definir o ciclo de trabalho do servomotor para 90 graus (1470µs)
    pwm_set_gpio_level(SERVO, SERVO_90);
    printf("Posicionando o servomotor a 90 graus (1470µs)\n");
    sleep_ms(5000); // Aguarda 5 segundos nesta posição

    // Definir o ciclo de trabalho do servomotor para 0 graus (500µs)
    pwm_set_gpio_level(SERVO, SERVO_0);
    printf("Posicionando o servomotor a 0 graus (500µs)\n");
    sleep_ms(5000); // Aguarda 5 segundos nesta posição

    while (true){
        // Movimentação periódica suave do servomotor entre 0 e 180 graus
        printf("Movimentação suave do servomotor entre 0 e 180 graus:\n");
        for (int i = SERVO_0; i <= SERVO_180; i += 5) {
            pwm_set_gpio_level(SERVO, i);
            printf("Ciclo ativo: %dµs\n", i);
            sleep_ms(10); // Atraso de 10ms para movimentação suave
        }
        for (int i = SERVO_180; i >= SERVO_0; i -= 5) {
            pwm_set_gpio_level(SERVO, i);
            printf("Ciclo ativo: %dµs\n", i);
            sleep_ms(10); // Atraso de 10ms para movimentação suave
        }
    }
}
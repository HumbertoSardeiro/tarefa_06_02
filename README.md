# **Controle de Servomotor por PWM - Raspberry Pi Pico W**

## **Descrição**

Este projeto implementa o controle de um servomotor utilizando o módulo PWM (Pulse Width Modulation) do microcontrolador Raspberry Pi Pico W. A simulação ocorre na plataforma Wokwi e permite controlar o ângulo do servomotor em diferentes posições através da variação do ciclo de trabalho do PWM.
O sistema posiciona o servomotor inicialmente em três ângulos fixos (180°, 90° e 0°), aguardando 5 segundos em cada posição. Em seguida, realiza um movimento suave e cíclico entre 0° e 180°, aumentando e diminuindo o ciclo de trabalho gradualmente para garantir um movimento fluido.

## **Componentes**

- 1x Raspberry Pi Pico W
- 1x Servomotor (motor micro servo padrão - Wokwi)

## **Requisitos da Tarefa**

**Frequência PWM:** 
- Configurar a GPIO 22 para gerar um sinal PWM com frequência de aproximadamente 50Hz (período de 20ms).

**Posicionamento do Servomotor:**
- Definir um ciclo de trabalho de 2.400µs para posicionar o servo a 180° e aguardar 5 segundos.
- Definir um ciclo de trabalho de 1.470µs para posicionar o servo a 90° e aguardar 5 segundos.
- Definir um ciclo de trabalho de 500µs para posicionar o servo a 0° e aguardar 5 segundos.

**Movimentação Periódica:** 
- Criar uma rotina para movimentar suavemente o servo entre 0° e 180°, com incrementos de ciclo ativo de ±5µs a cada 10ms.

## **Observações**

A simulação deste projeto pode ser realizada na plataforma online Wokwi.

## **Execução do Código**

Compile e carregue o código no Raspberry Pi Pico W utilizando o ambiente de desenvolvimento adequado (como o Pico SDK).
Execute a simulação na plataforma Wokwi para visualizar o comportamento do servomotor.

## **Vídeo Demonstrativo**

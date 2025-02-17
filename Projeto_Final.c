//                                                ***  Autor: Josemar Joel Damião Sebastião  ***
//                                                       ***  Título: Projeto Final  ***
//                                                             *** Embarcatech ***
//                                                     *** HBR - Instituto Hardware BR ***
//                                                             *** Campinas/SP ***

#include <stdio.h> // Esta biblioteca é usada para as funções de entrada e saída, como printf, que permite enviar mensagens para o terminal.
#include "pico/stdlib.h" // Contém funções básicas da plataforma Raspberry Pi Pico, como inicialização de GPIO e funções de temporização.
#include "hardware/adc.h" // Fornece funções para controlar o módulo ADC, necessário para converter sinais analógicos em digitais.


int main(void) { // Função principal, coração do programa.
    
    stdio_init_all(); // Prepara a comunicação serial, permitindo o uso da função printf para enviar dados para o console.
    adc_init(); // Prepara o ADC para começar a realizar leituras dos canais
    adc_set_temp_sensor_enabled(true); // Ativa o sensor interno de temperatura interno do RP2040.
    adc_select_input(4); // Configura a entrada ADC para 4, que corresponde ao 5º canal ADC.
           
    while (true) { // Loop infinito, realiza continuamente as seguintes ações:

        uint16_t raw = adc_read(); //  Lê o valor atual do canal ADC selecionado
        const float conversion_factor = 3.3f / (1<<12); // Converte as saídas ADC brutas em tensão
        float result = raw * conversion_factor; // Converte a tensão em temperatura
        float temp = 27 - (result - 0.706)/0.001721; // Equação que converte o valor lido da temperatura em graus celsius
        printf("\nTemperatura no RP2040 da BitDogLab = %f ºc\n", temp); // Impressão da temperatura em graus celcius lida para o serial monitor.
        sleep_ms(3000); // Espera 3 segundos antes de realizar a próxima leitura.

    }
}

#include <stdio.h>
#include "pico/stdlib.h"

#include "lcd.h"

// Eleccion de I2C a usar
#define I2C         i2c0
// Eleccion de GPIO para SDA
#define SDA_GPIO    16
// Eleccion de GPIO para SCL
#define SCL_GPIO    17
// Direccion de 7 bits del adaptador del LCD
#define ADDR        0x27

/**
 * @brief Programa principal
*/
int main(void) {
    // Inicializo el I2C con un clock de 100 KHz
    i2c_init(I2C, 100000);
    // Habilito la funcion de I2C en los GPIOs
    gpio_set_function(SDA_GPIO, GPIO_FUNC_I2C);
    gpio_set_function(SCL_GPIO, GPIO_FUNC_I2C);
    // Habilito pull-ups
    gpio_pull_up(SDA_GPIO);
    gpio_pull_up(SCL_GPIO);
    // Inicializo LCD
    lcd_init(I2C, ADDR);
    // Limpio pantalla
    lcd_clear();
    // Imprimo mensaje fijo
    lcd_string("Tiempo pasado");

    // Contador
    uint16_t i = 0;
    // Variable para imprimir el mensaje
    char str[16];

    while (true) {
        // Armo un string con la variable de contador y la incremento
        sprintf(str, "T = %d seg", i++);
        // Muevo el cursor al comienzo de la segunda fila
        lcd_set_cursor(1, 0);
        // Imprimo el mensaje
        lcd_string(str);
        // Demora
        sleep_ms(1000);
    }
}

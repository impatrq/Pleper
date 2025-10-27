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
    // Limpio el LCD
    lcd_clear();
    // Escribo al comienzo
    lcd_string("Hello");
    // Muevo el cursor a la segunda fila, tercer columna
    lcd_set_cursor(1, 2);
    // Escribo
    lcd_string("from RPi Pico!");

    while (true);
}

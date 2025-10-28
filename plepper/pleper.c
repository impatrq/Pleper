#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "hardware/adc.h"
#include "lcd.h"
#include <stdio.h>

#define GPIO_SDA 6
#define GPIO_SCL 7
#define ADC_PIN 26 // GPIO26 es ADC0

// Constantes para la conversión ADC
#define ADC_MAX_VAL 4095.0f 
#define VREF 3.3f           

// **IMPORTANTE**: Define aquí el voltaje máximo del capacitor. 
#define V_CAP_MAX 13.2f 

int main(void) {
    // Inicialización I2C para el LCD
    i2c_init(i2c1, 100000UL);
    gpio_set_function(GPIO_SDA, GPIO_FUNC_I2C);
    gpio_set_function(GPIO_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(GPIO_SDA);
    gpio_pull_up(GPIO_SCL);
    lcd_init(i2c1, 0x27);

    // Inicialización del ADC
    adc_init();
    adc_gpio_init(ADC_PIN); 
    adc_select_input(0); 
    
// ... (Tus includes, defines y la parte inicial de main() ) ...

    char buffer[16];
    
while (true) {
    uint16_t raw_value = adc_read();
    float voltage = ((float)raw_value / ADC_MAX_VAL) * VREF;
    int porcentaje = (int)((voltage / V_CAP_MAX) * 100.0f);

    if (porcentaje < 0) porcentaje = 0;
    if (porcentaje > 100) porcentaje = 100;

    lcd_clear();

    lcd_set_cursor(0, 0);
    lcd_string("CARGA CAPACITOR");

    lcd_set_cursor(1, 0);
    lcd_char('[');

    int bloques = porcentaje / 10; // 10 bloques posibles

    for (int i = 0; i < 10; i++) {
        if (i < bloques)
            lcd_char(0); // lleno
        else
            lcd_char(1); // vacío
    }

    lcd_char(']');

    char buffer[6];
    snprintf(buffer, sizeof(buffer), " %d%%", porcentaje);
    lcd_string(buffer);

    sleep_ms(250);
 }

}
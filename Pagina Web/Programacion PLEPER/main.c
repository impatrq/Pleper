#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/i2c.h"
#include "lcd1602_i2c.h"  // Asumiendo que usás una librería externa LCD I2C compatible

#define ADC_PIN 26 // GP26 = ADC0
#define LIGHTS_GPIO 15

// Parámetros de la batería
#define MAX_VOLTAGE 13.8  // Plomo ácido llena (ajustable)
#define MIN_VOLTAGE 11.5  // Vacía (ajustable)

// LCD I2C
#define I2C_PORT i2c0
#define SDA_PIN 4
#define SCL_PIN 5
#define LCD_ADDR 0x27  // Dirección común, puede ser 0x3F

void init_adc() {
    adc_init();
    adc_gpio_init(ADC_PIN);
    adc_select_input(0);
}

float read_voltage() {
    uint16_t raw = adc_read();
    float v_ref = 3.3;
    float voltage = raw * v_ref / 4095.0;

    // Suponiendo divisor resistivo de 10k y 2k (ajustar según tu circuito)
    float battery_voltage = voltage * ((10.0 + 2.0) / 2.0);
    return battery_voltage;
}

int voltage_to_percent(float voltage) {
    if (voltage >= MAX_VOLTAGE) return 100;
    if (voltage <= MIN_VOLTAGE) return 0;
    return (int)(((voltage - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE)) * 100.0);
}

int main() {
    stdio_init_all();
    init_adc();

    // Inicializar I2C y LCD
    i2c_init(I2C_PORT, 100 * 1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);
    lcd_init(LCD_ADDR, I2C_PORT); // Dependiendo de librería

    // Inicializar salida para luces
    gpio_init(LIGHTS_GPIO);
    gpio_set_dir(LIGHTS_GPIO, GPIO_OUT);

    while (true) {
        float battery_voltage = read_voltage();
        int battery_percent = voltage_to_percent(battery_voltage);

        char line1[16], line2[16];
        snprintf(line1, sizeof(line1), "Bateria: %.1fV", battery_voltage);
        snprintf(line2, sizeof(line2), "Carga: %d%%", battery_percent);

        lcd_set_cursor(0, 0);
        lcd_print(line1);
        lcd_set_cursor(0, 1);
        lcd_print(line2);

        if (battery_percent >= 100) {
            gpio_put(LIGHTS_GPIO, 1); // Enciende luces
        } else {
            gpio_put(LIGHTS_GPIO, 0); // Apaga luces
        }

        sleep_ms(1000);
    }
}
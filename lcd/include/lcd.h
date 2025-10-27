#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

// Comandos
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// Flags para tipo de entrada
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYLEFT 0x02

// Flags para control de display y cursor
#define LCD_BLINKON 0x01
#define LCD_CURSORON 0x02
#define LCD_DISPLAYON 0x04

// Flags para control de movimiento de cursor
#define LCD_MOVERIGHT 0x04
#define LCD_DISPLAYMOVE 0x08

// Flags para seteo de funcion
#define LCD_5x10DOTS 0x04
#define LCD_2LINE 0x08
#define LCD_8BITMODE 0x10

// Flah para control de backlight
#define LCD_BACKLIGHT 0x08

// Comando de habilitar enable
#define LCD_ENABLE_BIT 0x04

// Modos para el send byte
#define LCD_CHARACTER  1
#define LCD_COMMAND    0

// Dimensiones del display
#define MAX_LINES      2
#define MAX_CHARS      16

// Function prototypes
void i2c_write_byte(uint8_t val);
void lcd_toggle_enable(uint8_t val);
void lcd_send_byte(uint8_t val, int mode);
void lcd_clear(void);
void lcd_set_cursor(int line, int position);
void lcd_char(char val);
void lcd_string(const char *s);
void lcd_init(i2c_inst_t *i2c, uint8_t address);
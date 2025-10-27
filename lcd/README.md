# rpipico-lcd

Biblioteca para usar LCDs con la Raspberry Pi Pico. Puede ser usada descargandola e incluyendola en un proyecto de forma particular o puede incluirse en PlatformIO directamente modificando el `platformio.ini` agregando la linea:

```
lib_deps = https://github.com/carlassaraf/rpipico-lcd.git
```

Si se elige usarla en un proyecto sin PlatformIO, incluir este repositorio en el proyecto y agregar en el `CMakeLists.txt1` del proyecto:

```cmake
# Añadir la subcarpeta donde está la biblioteca LCD
add_subdirectory(rpipico-lcd)
```

Agregar esas lineas luego de la directiva `project`.

## Uso de la biblioteca

Una vez incluida la biblioteca con `#include "lcd.h"` podemos hacer algo basico con el LCD usando:

```c
// Inicializa el LCD con el I2C0 y la direccion de 7 bits 0x27
lcd_init(i2c0, 0x27);
// Limpia la pantalla
lcd_clear();
// Escribe un mensaje
lcd_string("Hello world!");
```

La inicializacion del I2C de la Raspberry Pi Pico y los GPIO deben hacerse previamente.

## Ejemplos

Los ejemplos que van a encontrarse en el repositorio son:

| Ejemplo | Descripcion |
| ------- | ----------- |
| [hello_world](examples/hello_world/main.c) | Ejemplo basico que escribe un mensaje fijo en dos lineas del LCD |
| [sprintf](examples/sprintf/main.c) | Ejemplo que usa el sprintf de la biblioteca de stdio.h para imprimir una variable en el LCD |

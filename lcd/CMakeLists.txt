# Crear la biblioteca estática "lcd" con los archivos fuente
add_library(lcd STATIC
    src/lcd.c
)

# Linkeo dependencias de la bibliotecas
target_link_libraries(lcd
    pico_stdlib
    hardware_i2c
)

# Incluir las cabeceras de la biblioteca
target_include_directories(lcd PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

# Generated CMake Pico project file
cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.3.1)
set(toolchainVersion 15_2_Rel1)
set(picotoolVersion 2.3.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Sisyphus C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Define el ejecutable y sus archivos fuente
# (Si usas main.cpp o tienes archivos dentro de una carpeta como src/main.c, edita esta línea)
add_executable(Sisyphus
    main.c
)

pico_set_program_name(Sisyphus "Sisyphus")
pico_set_program_version(Sisyphus "0.1")

# Salida de texto (printf) por USB habilitada (1) y UART deshabilitada (0)
pico_enable_stdio_uart(Sisyphus 0)
pico_enable_stdio_usb(Sisyphus 1)

# Vincular la librería estándar del Pico SDK
target_link_libraries(Sisyphus
    pico_stdlib
)

# Carpetas de cabeceras (.h)
target_include_directories(Sisyphus PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Generar archivos finales (.uf2, .elf, .bin) para flashear el Pico
pico_add_extra_outputs(Sisyphus)
cmake_minimum_required(VERSION 4.1)

project(esp8266_multitool C)

set(CMAKE_C_STANDARD 23)

add_executable(esp8266_multitool
        src/main.c
        src/file_reader.c
        src/hexdump_viewer.c
        src/commandline_parser.c)

target_include_directories(esp8266_multitool PUBLIC include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/bin")
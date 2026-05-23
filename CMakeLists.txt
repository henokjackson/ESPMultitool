cmake_minimum_required(VERSION 4.1)

project(esp8266_multitool C)

set(CMAKE_C_STANDARD 23)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/bin")

file(GLOB SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.c")

add_executable(esp8266_multitool ${SOURCES})

target_include_directories(esp8266_multitool PUBLIC include)
cmake_minimum_required(VERSION 3.17)
project(lab2 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab2 main.c domain/Estate.c domain/Estate.h repository/Repository.c repository/Repository.h service/Service.c service/Service.h ui/Ui.c ui/Ui.h vector/DynamicArray.c vector/DynamicArray.h)
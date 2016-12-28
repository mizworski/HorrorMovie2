cmake_minimum_required(VERSION 3.6)
project(HorrorMovie2)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "-Wpedantic -Werror -Wall -Wextra")

set(SOURCE_FILES citizen.cc citizen.h monster.cc monster.h smalltown.cc smalltown.h horror_example.cc)
add_executable(HorrorMovie2 ${SOURCE_FILES})
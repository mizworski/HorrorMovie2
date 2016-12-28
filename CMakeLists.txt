cmake_minimum_required(VERSION 3.6)
project(HorrorMovie2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES citizen.cc citizen.h monster.cc monster.h smalltown.cc smalltown.h)
add_executable(HorrorMovie2 ${SOURCE_FILES})
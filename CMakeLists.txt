cmake_minimum_required(VERSION 3.10)
project(CardGame)

add_executable(CardGame main.cpp)

enable_testing()
add_executable(TestCardGame tests/test.cpp)
add_test(NAME TestCardGame COMMAND TestCardGame)

cmake_minimum_required(VERSION 3.14)
project(TimerProject)

set(CMAKE_CXX_STANDARD 17)

# Основная программа
add_executable(timer_app src/main.cpp src/timer.cpp)

# Тесты
enable_testing()
find_package(GTest REQUIRED)
add_executable(timer_tests tests/test_timer.cpp src/timer.cpp)
target_link_libraries(timer_tests GTest::gtest GTest::gtest_main)
add_test(NAME TimerTests COMMAND timer_tests)
#include <gtest/gtest.h>
#include "../src/timer.h"
#include <thread>
#include <chrono>

// Тест 1: Запуск и завершение
TEST(TimerTest, StartAndFinish) {
    Timer t;
    t.start(1);
    std::this_thread::sleep_for(std::chrono::milliseconds(1100));
    EXPECT_EQ(t.getState(), Timer::State::FINISHED);
}

// Тест 2: Остановка до завершения
TEST(TimerTest, StopBeforeFinish) {
    Timer t;
    t.start(5);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    t.stop();
    EXPECT_EQ(t.getState(), Timer::State::IDLE);
}

// Тест 3: Нельзя запустить отрицательное время
TEST(TimerTest, InvalidStart) {
    Timer t;
    t.start(-5);
    EXPECT_EQ(t.getState(), Timer::State::IDLE);
    t.start(0);
    EXPECT_EQ(t.getState(), Timer::State::IDLE);
}

// Тест 4: Проверка оставшегося времени
TEST(TimerTest, RemainingTime) {
    Timer t;
    t.start(3);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    int rem = t.getRemaining();
    EXPECT_GE(rem, 2);
    EXPECT_LE(rem, 3);
    t.stop();
}

// Тест 5: Callback вызывается
TEST(TimerTest, CallbackWorks) {
    Timer t;
    bool callbackCalled = false;
    t.setTickCallback([&](int rem) {
        callbackCalled = true;
    });
    t.start(1);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    EXPECT_TRUE(callbackCalled);
    t.stop();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
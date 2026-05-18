#include "timer.h"
#include <chrono>

Timer::Timer() : state(State::IDLE), totalSeconds(0), remaining(0), stopFlag(false) {}

Timer::~Timer() {
    stop();
    if (worker.joinable()) worker.join();
}

void Timer::setTickCallback(std::function<void(int)> callback) {
    onTick = callback;
}

void Timer::start(int seconds) {
    if (seconds <= 0) return;
    if (state == State::RUNNING) return;
    
    stop();
    if (worker.joinable()) worker.join();
    
    totalSeconds = seconds;
    remaining = seconds;
    state = State::RUNNING;
    stopFlag = false;
    worker = std::thread(&Timer::run, this);
}

void Timer::stop() {
    stopFlag = true;
    state = State::IDLE;
}

Timer::State Timer::getState() const { return state; }
int Timer::getRemaining() const { return remaining; }

void Timer::run() {
    auto startTime = std::chrono::steady_clock::now();
    
    while (!stopFlag && state == State::RUNNING) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
        
        remaining = totalSeconds - elapsed;
        
        if (remaining <= 0) {
            remaining = 0;
            state = State::FINISHED;
            if (onTick) onTick(0);
            break;
        }
        
        if (onTick) onTick(remaining);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
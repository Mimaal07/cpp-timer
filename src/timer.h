#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>
#include <functional>

class Timer {
public:
    enum class State { IDLE, RUNNING, FINISHED };
    
    Timer();
    ~Timer();
    
    void start(int seconds);
    void stop();
    State getState() const;
    int getRemaining() const;
    void setTickCallback(std::function<void(int)> callback);
    
private:
    void run();
    
    std::thread worker;
    State state;
    int totalSeconds;
    int remaining;
    bool stopFlag;
    std::function<void(int)> onTick;
};

#endif
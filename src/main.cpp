#include "timer.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>

// Функция парсинга времени
int parseTimeString(const std::string& input) {
    std::vector<int> parts;
    std::stringstream ss(input);
    std::string part;
    
    while (std::getline(ss, part, ':')) {
        parts.push_back(std::stoi(part));
    }
    
    if (parts.empty() && input.find(' ') != std::string::npos) {
        std::stringstream ss2(input);
        while (ss2 >> part) {
            parts.push_back(std::stoi(part));
        }
    }
    
    if (parts.empty()) return std::stoi(input);
    if (parts.size() == 1) return parts[0];
    if (parts.size() == 2) return parts[0] * 60 + parts[1];
    if (parts.size() == 3) return parts[0] * 3600 + parts[1] * 60 + parts[2];
    return 0;
}

// Форматирует секунды в ЧЧ:ММ:СС
std::string formatTime(int seconds) {
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int secs = seconds % 60;
    
    std::ostringstream oss;
    if (hours > 0) {
        oss << hours << ":";
        if (minutes < 10) oss << "0";
    }
    oss << minutes << ":";
    if (secs < 10) oss << "0";
    oss << secs;
    
    return oss.str();
}

// Рисует прогресс-бар
void printProgress(int remaining, int total) {
    if (total <= 0) return;
    
    int percent = (total - remaining) * 100 / total;
    int barWidth = 30;
    int pos = barWidth * percent / 100;
    
    std::cout << "\r[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << percent << "%  " << formatTime(remaining) << "   " << std::flush;
}

int main() {
    Timer timer;
    std::string timeInput;
    
    std::cout << "=== TIMER ===" << std::endl;
    std::cout << "Enter time (examples: 5, 1:30, 1:30:45): ";
    std::getline(std::cin, timeInput);
    
    int seconds = parseTimeString(timeInput);
    
    if (seconds <= 0) {
        std::cout << "Invalid time!" << std::endl;
        return 1;
    }
    
    std::cout << "Starting timer for " << formatTime(seconds) << std::endl;
    
    timer.setTickCallback([&](int rem) {
        printProgress(rem, seconds);
    });
    
    timer.start(seconds);
    
    while (timer.getState() == Timer::State::RUNNING) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    std::cout << std::endl << "TIME'S UP!" << std::endl;
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
}
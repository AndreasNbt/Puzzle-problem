#include "Timer.h"

void Timer::start() {
    startTime = system_clock::now();
    clockRunning = true;
}

void Timer::stop() {
    endTime = system_clock::now();
    clockRunning = false;
}

double Timer::getElapsedMicroSeconds() {

    if (clockRunning) {
        endTime = system_clock::now();
        clockRunning = false;
    }

    return duration_cast<microseconds>(endTime-startTime).count();

}


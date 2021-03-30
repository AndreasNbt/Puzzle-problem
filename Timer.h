#ifndef __TIMER_H
#define __TIMER_H

#include <chrono>
using namespace std::chrono;
class Timer {
    public:
        void start();
        void stop();
        double getElapsedMicroSeconds();
    private:
        time_point<system_clock> startTime;
        time_point<system_clock> endTime;
        bool clockRunning;
};


#endif

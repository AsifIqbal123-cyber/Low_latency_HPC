#pragma once 
#include <chrono>
using namespace std;

class Timer {
public:
    Timer() { reset();}

    void reset(){
        start_time_ = chrono::high_resolution_clock::now();
    }


    double eleapsed_microseconds() const {
        auto now = chrono::high_resolution_clock::now();
        return chrono::duration<double, micro>(now - start_time_).count();

    }

private:
    chrono::high_resolution_clock::time_point start_time_;

};
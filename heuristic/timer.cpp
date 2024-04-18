#include "../base.cpp"

struct Timer {
    chrono::system_clock::time_point start_time;

    Timer() : start_time(chrono::system_clock::now()) {}

    double get_time() {
        return (double)chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start_time).count() / 1000;
    }
} timer;
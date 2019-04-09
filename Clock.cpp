#include "Clock.h"
void Clock::start() {
    t = clock();
}
double Clock::getTime() {
    return (double)(clock() - t) / CLOCKS_PER_SEC;
}

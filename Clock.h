#include <ctime>
class Clock {
  public:
    void start();
    double getTime();
  private:
    clock_t t;
};

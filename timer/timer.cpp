#include "timer.h"
#include <format>
#include <chrono>
//---------------------------------------------------------------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------------------------------------------------------------
namespace MyTime {
  class TimeMeasurer : public ITimeMeasurer {
  public:
    TimeMeasurer() {};

    virtual void Start() noexcept override {
      start = chrono::high_resolution_clock::now();
    }

    virtual void Stop() noexcept override {
      interval = chrono::high_resolution_clock::now() - start;
    }

    virtual float GetInterval() noexcept override {
      return interval.count();
    }

    virtual string getStr(const string &prm = "Time of run = ") noexcept override {
      return format("{}{:.7f} sec.", prm, interval.count());
    }

    virtual ~TimeMeasurer() override {
    }
  private:
    std::chrono::time_point<std::chrono::steady_clock> start;
    std::chrono::duration<float> interval;
  };

  ITimeMeasurer::~ITimeMeasurer() {}

  TIMER_DLL ITimeMeasurer *GetTimeMeasurer() noexcept {
    return new TimeMeasurer();
  }
}
//---------------------------------------------------------------------------------------------------------------------------------
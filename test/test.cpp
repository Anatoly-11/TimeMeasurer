#include "pch.h"
#include "timer.h"
#include <chrono>
#include <thread>
using namespace std;
//---------------------------------------------------------------------------------------------------------------------------------
  /*size_t i = 0;
  for(; i < SIZE; ++i) {
    msr->Start();
    this_thread::sleep_for(chrono::milliseconds(times[i]));
    msr->Stop();
    intervals[i] = msr->GetInterval();
  }
  float vals[5][8] = {
    {0.0190334f, 0.0447501f, 0.109743f, 0.301195f, 0.505716f, 1.01227f, 3.00105f, 5.00335f},
    {0.0144846f, 0.0319098f, 0.108691f, 0.301229f, 0.505653f, 1.01231f, 3.0004f, 5.01072f},
    {0.016834f, 0.0309249f, 0.109679f, 0.301255f, 0.500667f, 1.01026f, 3.01215f, 5.00445f},
    {0.0217114f, 0.0446157f, 0.10867f, 0.300235f, 0.503657f, 1.0043f, 3.01292f, 5.01432f},
    {0.0159264f, 0.0363211f, 0.107286f, 0.312248f, 0.509688f, 1.01228f, 3.00805f, 5.01528f}
  };
  for(size_t i = 0; i < SIZE; ++i) {
    for(size_t j = 0; j < 5; ++j) {
      test[i] += vals[j][i];
    }
    test[i] /= 5.0f;
  }
  for(size_t i = 0; i < SIZE; ++i) {
    for(size_t j = 0; j < 5; ++j) {
      diff[i] += (vals[j][i] - test[i]) * (vals[j][i] - test[i]);
    }
    diff[i] = 1.5f*sqrt(diff[i] / 20.0f); // squaremean deviation
  }
  for(i = 0; i < SIZE - 1; ++i) {
    cout << test[i] << ", ";
  }
  cout << test[i] << endl;
  for(i = 0; i < SIZE - 1; ++i) {
    cout << diff[i] << ", ";
  }
  cout << diff[i] << endl;*/
TEST(TestCaseName, TestName) {
  MyTime::ITimeMeasurer *msr = MyTime::GetTimeMeasurer();
  EXPECT_TRUE(msr != nullptr);
  constexpr int SIZE = 8;
  float intervals[SIZE];
  int times[SIZE]{10, 30, 100, 300, 500, 1000, 3000, 5000}; // миллисекунды
  size_t i = 0;
  for(; i < SIZE; ++i) {
    msr->Start();
    this_thread::sleep_for(chrono::milliseconds(times[i]));
    msr->Stop();
    intervals[i] = msr->GetInterval();
  }
  delete msr;
  //float test[SIZE]{0.017598f, 0.0377043f, 0.108814f, 0.303232f, 0.505076f, 1.01028f, 3.00691f, 5.00962f};
    //diff[SIZE]{1.8989e-3f, 4.48573e-3f, 6.69302e-4f, 3.39312e-3f, 2.21133e-3f, 2.31996e-3f, 3.99118e-3f, 3.69526e-3f};
    //diff[SIZE]{2e-3f, 5e-3f, 1e-3f, 439312e-3f, 2.21133e-3f, 2.31996e-3f, 3.99118e-3f, 3.69526e-3f};
  for(size_t i = 0; i < SIZE; ++i) {
    ASSERT_NEAR(static_cast<float>(times[i]/1000.0f), intervals[i], 1.5e-2f);// Если уменьшить не пройдёт...
    // Как видите точность низкая... Хоят наносекундный таймер с точностью до 100 нс.
  }
}
//---------------------------------------------------------------------------------------------------------------------------------
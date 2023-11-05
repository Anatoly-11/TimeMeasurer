#pragma once
#ifndef _TIMER_H_
#define _TIMER_H_ 1.0
//---------------------------------------------------------------------------------------------------------------------------------
/*
  Interface for time measure between Start and Stor and get them it string form. After using pointer returned by GetTimeMeasurer
  function must be deleted manually for avoid memory leak.
*/
//---------------------------------------------------------------------------------------------------------------------------------
#ifdef TIMER_EXPORTS
#define TIMER_DLL __declspec(dllexport)
#else 
#define TIMER_DLL __declspec(dllimport)
#endif 
//---------------------------------------------------------------------------------------------------------------------------------
#include <string>
namespace MyTime {
  class TIMER_DLL ITimeMeasurer {
  public:
    virtual void Start() noexcept = 0;
    virtual void Stop() noexcept = 0;
    virtual float GetInterval() noexcept = 0; 
    virtual std::string getStr(const std::string &prm) noexcept = 0;
    virtual ~ITimeMeasurer() = 0;
  }; // !class ITimeMeasurer(interface)

  TIMER_DLL ITimeMeasurer *GetTimeMeasurer() noexcept; // return pointer to interface
} // !namespace MyTime
//---------------------------------------------------------------------------------------------------------------------------------
#endif // !_TIMER_H_
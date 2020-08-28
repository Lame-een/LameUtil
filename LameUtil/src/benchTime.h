#pragma once
#include <iostream>
#include <chrono>

/*
RAII based timer class.

Usage: 
	Wrap the piece of code you want to measure into a scope.
	Construct the class at the beginning of the scope
	At the end of the scope the class gets destroyed and prints out the time elapse since construction to the standard output.

BenchTimer()
Default initializator, the timer will be in milliseconds.

BenchTimer(TimerType type)
	type - enum which defines the precision of the timer, accepted values are: TimerType::MICRO, TimerType::MILLI, TimerType::SEC

*/

namespace lameutil
{
	class BenchTimer
	{
	public:
		enum class TimerType
		{
			MICRO, MILLI, SEC
		};
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
		TimerType timerType = TimerType::MILLI;
	public:

		BenchTimer()
		{
			startTime = std::chrono::high_resolution_clock::now();
		}
		BenchTimer(TimerType type)
		{
			timerType = type;
			startTime = std::chrono::high_resolution_clock::now();
		}

		~BenchTimer()
		{
			std::chrono::time_point<std::chrono::high_resolution_clock> endTime = std::chrono::high_resolution_clock::now();

			if(timerType == TimerType::MICRO)
			{
				std::cout << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() << " us";
			}
			else if(timerType == TimerType::MILLI)
			{
				std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms";
			}
			else
			{
				std::cout << std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count() << " s";
			}
			std::cout << std::endl;
		}
	};
}
#pragma once
#include <iostream>
#include <chrono>

/*
RAII based timer class.

Usage:
	Wrap the piece of code you want to measure into a scope.
	Construct the class at the beginning of the scope
	At the end of the scope the class gets destroyed and prints out the time elapse since construction to the standard output.

	OR


	Use the:
		BENCHMARK_SCOPE(scopeName) - for benchmarking the scope
		BENCHMARK_FUNCTION() - for benchmarking the function
	macros with the following preprocessor definitions:
		BENCHMARK_SEC - for seconds
		BENCHMARK_MILLI - for milliseconds
		BENCHMARK_MICRO - for microseconds

BenchTimer()
Default initializator, the timer will be in milliseconds.

BenchTimer(TimerType type)
	type - enum which defines the precision of the timer, accepted values are: TimerType::MICRO, TimerType::MILLI, TimerType::SEC

*/

#if BENCHMARK == 1
#define BENCHMARK_SCOPE(scopeName) lameutil::BenchTimer timer##__LINE__(scopeName, lameutil::BenchTimer::TimerType::SEC)
#elif BENCHMARK == 2
#define BENCHMARK_SCOPE(scopeName) lameutil::BenchTimer timer##__LINE__(scopeName, lameutil::BenchTimer::TimerType::MILLI)
#elif BENCHMARK == 3
#define BENCHMARK_SCOPE(scopeName) lameutil::BenchTimer timer##__LINE__(scopeName, lameutil::BenchTimer::TimerType::MICRO)
#else
#define BENCHMARK_SCOPE(scopeName)
#endif

#if BENCHMARK
#define BENCHMARK_FUNCTION() BENCHMARK_SCOPE(__FUNCSIG__)
#else 
#define BENCHMARK_FUNCTION()
#endif

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

		std::string name;
		TimerType timerType;
	public:

		BenchTimer() : name{}, timerType{ TimerType::MILLI }
		{
			startTime = std::chrono::high_resolution_clock::now();
		}

		BenchTimer(std::string name) : name{ name }, timerType{ TimerType::MILLI }
		{
			startTime = std::chrono::high_resolution_clock::now();
		}

		BenchTimer(std::string name, TimerType type) : name{ name }, timerType{ type }
		{
			startTime = std::chrono::high_resolution_clock::now();
		}

		~BenchTimer()
		{
			std::chrono::time_point<std::chrono::high_resolution_clock> endTime = std::chrono::high_resolution_clock::now();

			std::cout << "Timer " << name << ": ";

			if (timerType == TimerType::MICRO)
			{
				std::cout << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() << " us";
			}
			else if (timerType == TimerType::MILLI)
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
#pragma once

#include<Windows.h>
#include <chrono>

#include "GlobalValues.h"

class Timer {

public:

	explicit Timer();
	~Timer() = default;

	std::chrono::steady_clock::time_point startTimer();

	BOOL checkPeriodHasEndedSinceStart(const DOUBLE time); 

	DOUBLE timeElapsedSinceStart();

private:
	std::chrono::steady_clock::time_point _startTime;
};

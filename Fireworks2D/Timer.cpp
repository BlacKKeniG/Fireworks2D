#include "Timer.h"

Timer::Timer() : _startTime{} {};

std::chrono::steady_clock::time_point Timer::startTimer() {
	return _startTime = std::chrono::steady_clock::now();
}

BOOL Timer::checkPeriodHasEndedSinceStart(const DOUBLE time) {

	std::chrono::duration<DOUBLE> duretion{ (std::chrono::steady_clock::now() - _startTime) };
	return duretion.count() >= time;
}

DOUBLE Timer::timeElapsedSinceStart() {
	std::chrono::duration<DOUBLE> duretion{ (std::chrono::steady_clock::now() - _startTime) };
	return duretion.count();
}
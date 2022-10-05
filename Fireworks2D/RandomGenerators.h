#pragma once

#include <Windows.h>
#include <random>
#include "eColor.h"

INT random_INT_Generator(const INT minRangeValue, const INT maxRangeValue);

DOUBLE random_DOUBLE_Generator(const DOUBLE minRangeValue, const DOUBLE maxRangeValue);

eColor randomColorGenerator();
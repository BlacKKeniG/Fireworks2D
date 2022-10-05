#include "RandomGenerators.h"

INT random_INT_Generator(const INT minRangeValue, const INT maxRangeValue) {

	if (minRangeValue <= maxRangeValue) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<INT> dist(minRangeValue, maxRangeValue);
		return dist(gen);
	} return 0;
};

DOUBLE random_DOUBLE_Generator(const DOUBLE minRangeValue, const DOUBLE maxRangeValue) {

	if (minRangeValue <= maxRangeValue) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<DOUBLE> dist(minRangeValue, maxRangeValue);
		return dist(gen);
	} return 0;
};

eColor randomColorGenerator() {
	std::vector<eColor> vColor{ AQUA, BLUE, LIME, YELLOW,  SEA_SHELL, VIOLET, ORANGE, WHITE };
	return vColor[random_INT_Generator(0, vColor.size() - 1)];
}

#include "Projectile.h"

Projectile::Projectile() : Projectile({}, {}) {}

Projectile::Projectile(const COORD position, const eColor color)
	: FireworkObject(position, color) {

	Projectile::_width = DEFAUT_PROJECTALE_WIDTH;
	Projectile::_height = DEFAUT_PROJECTALE_HEIGHT;
}

VOID Projectile::explosion(std::list<std::shared_ptr<FireworkObject>>& list) {

	USHORT _minNumOfSpark{ 30 };
	USHORT _maxNumOfSpark{ 50 };
	USHORT _numOfSparks = random_INT_Generator(_minNumOfSpark, _maxNumOfSpark);
	
	for (size_t i = 0; i < _numOfSparks; i++) {
		std::shared_ptr<FireworkObject> newSpark{ new FireworkObject{ Projectile::_position, randomColorGenerator() } };
		newSpark->_flightSpeed = random_DOUBLE_Generator(7, 12);
		newSpark->_timeToExplosion = Projectile::_timeToExplosion / 2;
		newSpark->_flightDirectionAngle = random_DOUBLE_Generator(1, 360);
		newSpark->_flightTimer.startTimer();

		list.push_back(newSpark);
	}
}

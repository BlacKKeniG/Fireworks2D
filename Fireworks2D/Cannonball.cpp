#include "Cannonball.h"

#define DEFAULT_CANNOLBALL_WIDTH 10
#define DEFAULT_CANNOLBALL_HEIGHT 10

Cannonball::Cannonball() : Cannonball({}, {}) {}

Cannonball::Cannonball(const COORD position, const eColor color)
	: Projectile(position, color) {

	Cannonball::_width = DEFAULT_CANNOLBALL_WIDTH;
	Cannonball::_height = DEFAULT_CANNOLBALL_HEIGHT;
}

VOID Cannonball::explosion(std::list<std::shared_ptr<FireworkObject>>& list) {

	Projectile::explosion(list);

	USHORT _numOfInternalProjectiles{ 2 };

	USHORT count{ 1 };
	USHORT _angleDeviationInternalProjectileFromBasicTrajectory{ 10 };

	for (size_t i = 0; i < _numOfInternalProjectiles; i++) {

		std::shared_ptr<FireworkObject> newProjectale{ new Projectile{Cannonball::_position, randomColorGenerator() } };
		newProjectale->_flightSpeed = Cannonball::_flightSpeed * 2;
		newProjectale->_timeToExplosion = Cannonball::_timeToExplosion / 2;

		newProjectale->_flightDirectionAngle = (count % 2)
			? _flightDirectionAngle + _angleDeviationInternalProjectileFromBasicTrajectory
			: _flightDirectionAngle - _angleDeviationInternalProjectileFromBasicTrajectory;
		count++;
			
		newProjectale->_flightTimer.startTimer();

		list.push_back(newProjectale);
	}
	
}

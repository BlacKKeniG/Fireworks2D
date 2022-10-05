#include "Cannon.h"

Cannon::Cannon() : BaseObject()
, _minBarrelAngle{}
, _maxTBarrelAngle{}
, _minMuzzleVelocity{}
, _maxMuzzleVelocity{}
, _minTimeToExplosionOfLaunchedProgectile{}
, _maxTimeToExplosionOfLaunchedProgectile{}
, _timeReload{}
, _reloadTimer{} 
, _pProjectile{}
{
	Cannon::_width = CANNON_WIDTH;
	Cannon::_height = CANNON_HEIGHT;
}

BOOL Cannon::load() {

	if (_reloadTimer.checkPeriodHasEndedSinceStart(_timeReload)) {
		
		_pProjectile.reset(new Cannonball{ {}, randomColorGenerator() });

		return TRUE;
	}
	return FALSE;
}

std::shared_ptr<FireworkObject> Cannon::fire() {

	if (_pProjectile) {

		_pProjectile->_position.X = Cannon::_position.X + 15;
		_pProjectile->_position.Y = Cannon::_position.Y - 5;
		_pProjectile->_flightDirectionAngle = random_INT_Generator(_minBarrelAngle, _maxTBarrelAngle);
		_pProjectile->_flightSpeed = random_DOUBLE_Generator(_minMuzzleVelocity, _maxMuzzleVelocity);
		_pProjectile->_timeToExplosion = random_DOUBLE_Generator(_minTimeToExplosionOfLaunchedProgectile, _maxTimeToExplosionOfLaunchedProgectile);
		_pProjectile->_flightTimer.startTimer();

		std::shared_ptr<FireworkObject> temp{ _pProjectile };
		_pProjectile = nullptr;

		_reloadTimer.startTimer();

		return temp;
	}
	return nullptr;
}

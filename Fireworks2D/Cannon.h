#pragma once

#include "Cannonball.h"

#define CANNON_WIDTH 40
#define CANNON_HEIGHT 40

class Cannon : private BaseObject {

public:

	explicit Cannon();
	~Cannon() = default;

	const COORD& position() const {
		return  _position;
	}

	void setPosition(const COORD position) {
		_position = position;
	};

	SHORT width() const {
		return _width;
	}

	SHORT height() const {
		return _height;
	}

	BOOL load();

	std::shared_ptr<FireworkObject> fire();


	USHORT _minBarrelAngle;
	USHORT _maxTBarrelAngle;

	DOUBLE _minMuzzleVelocity;
	DOUBLE _maxMuzzleVelocity;

	DOUBLE _minTimeToExplosionOfLaunchedProgectile;
	DOUBLE _maxTimeToExplosionOfLaunchedProgectile;

	DOUBLE _timeReload;

private:
	
	std::shared_ptr<FireworkObject> _pProjectile;
	Timer _reloadTimer;
};


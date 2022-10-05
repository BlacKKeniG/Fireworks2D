#include "FireworkObject.h"

FireworkObject::FireworkObject() : FireworkObject({}, {}) {}
	
FireworkObject::FireworkObject(const COORD position, const eColor color)
	: BaseObject(position, DEFAULT_FIREWORKS_OBJECT_WIDTH, DEFAULT_FIREWORKS_OBJECT_HEIGHT)
	, _color{ color }
	, _flightTimer{}
	, _flightDirectionAngle{} 
	, _flightSpeed{}
	, _timeToExplosion{} {}

BOOL FireworkObject::fly() {

	if (!_flightTimer.checkPeriodHasEndedSinceStart(_timeToExplosion)) {

		//x = Vx * t
		//y = h + Vy * t — g * t² / 2
		DOUBLE _timeElapsedSinceStart{ _flightTimer.timeElapsedSinceStart() };
		_position.X += _flightSpeed * (_timeElapsedSinceStart)*cos(_flightDirectionAngle * PI / 180); 
		_position.Y += _flightSpeed * (_timeElapsedSinceStart)*sin(_flightDirectionAngle * PI / 180)
			+ GRAVITY * pow(_timeElapsedSinceStart, 2) / 2; 

		return TRUE;
	}
	return FALSE;
}



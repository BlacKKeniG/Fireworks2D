#pragma once

#include <Windows.h>
#include <iostream>
#include <list>

#include "eColor.h"
#include "BaseObject.h"
#include "Timer.h"
#include "GlobalValues.h"

#define DEFAULT_FIREWORKS_OBJECT_WIDTH  4
#define DEFAULT_FIREWORKS_OBJECT_HEIGHT 4

class FireworkObject : public BaseObject {

public:

	explicit FireworkObject();
	explicit FireworkObject(const COORD position, const eColor color);
	virtual ~FireworkObject() = default;

	BOOL fly();
	virtual VOID explosion(std::list<std::shared_ptr<FireworkObject>>& list) {};

	eColor _color;
	Timer _flightTimer;
	USHORT _flightDirectionAngle;
	DOUBLE _flightSpeed;
	DOUBLE _timeToExplosion;
};



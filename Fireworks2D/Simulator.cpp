#include "Simulator.h"

Simulator::Simulator()
	: _demoWindow{}
	, _rendering{}
	, _eRunFunctionActiveProc{ START_PROC }
	, _cannon{}
	, _listFireworkObjects{} {}

INT Simulator::run() {

	switch (_eRunFunctionActiveProc) 
	{
	case Simulator::START_PROC: {

		_rendering.initializeDrawingFieldInfo(_demoWindow.handle());

		USHORT _marginBottom{ 10 };

		COORD _cannonPosition{};
		_cannonPosition.X = _rendering._drawingFieldInfo._width / 2 - _cannon.width() / 2;
		_cannonPosition.Y = _rendering._drawingFieldInfo._height - _cannon.height() - _marginBottom;
		_cannon.setPosition(_cannonPosition);

		_cannon._minBarrelAngle = 260;
		_cannon._maxTBarrelAngle = 280;

		_cannon._minMuzzleVelocity = 10.5;
		_cannon._maxMuzzleVelocity = 11.5;

		_cannon._minTimeToExplosionOfLaunchedProgectile = 1.5;
		_cannon._maxTimeToExplosionOfLaunchedProgectile = 2.5;

		_cannon._timeReload = 1;

		_eRunFunctionActiveProc = MAIN_PROC;

	} break;

	case Simulator::MAIN_PROC: {

		_rendering.drawBackground();
		_rendering.drawCannon(_cannon.position());

		if (_cannon.load()) {

			_listFireworkObjects.push_back(_cannon.fire());
		}

		if (!_listFireworkObjects.empty()) {

			for (auto itFistObjects = _listFireworkObjects.begin() 
				, itLastObjects =  _listFireworkObjects.end()
				; itFistObjects != itLastObjects;) {

				if (!itFistObjects->get()->fly()) {
					itFistObjects->get()->explosion(_listFireworkObjects);
					itFistObjects = _listFireworkObjects.erase(itFistObjects);
				}
				else {
					_rendering.drawFireworkObject(
						  itFistObjects->get()->_position
						, itFistObjects->get()->_width
						, itFistObjects->get()->_height
						, itFistObjects->get()->_color
					);
					++itFistObjects;
				}
			}
		}

	} break;

	default:
		return 0;
		break;
	}
}
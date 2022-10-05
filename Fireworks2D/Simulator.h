#pragma once

#include<list>

#include "Rendering.h"
#include "DemoWindow.h"
#include "Cannon.h"

class  Simulator {

public:

	explicit Simulator ();
	~Simulator() = default;

	INT run();

private:

	static std::shared_ptr<Simulator> _instance;
	DemoWindow _demoWindow;
	Rendering _rendering;

	Cannon _cannon;

	std::list<std::shared_ptr<FireworkObject>> _listFireworkObjects;

	enum eRunFunctionProc {
		START_PROC,
		MAIN_PROC
	};
	eRunFunctionProc _eRunFunctionActiveProc;
};




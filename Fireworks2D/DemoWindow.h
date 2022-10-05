#pragma once

#include <windows.h>

#include "DemoWindowProc.h"

class DemoWindow {

	HWND _hWnd;
	WNDCLASSEX& initialize();

public:
	explicit DemoWindow(); 

	HWND handle() const {
		return _hWnd;
	}

	~DemoWindow() = default;
};

#include "DemoWindow.h"

DemoWindow::DemoWindow() {
	if (RegisterClassEx(&initialize())) {
		_hWnd = CreateWindowEx(
			NULL
			, L"DemoWindow"
			, L"Fireworks2D"
			, WS_POPUP | WS_MAXIMIZE | WS_VISIBLE
			, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT
			, NULL, NULL, NULL, NULL);
		UpdateWindow(_hWnd);
	}
}

WNDCLASSEX& DemoWindow::initialize() {
	WNDCLASSEX wcl{};
	wcl.lpszClassName = L"DemoWindow";
	wcl.lpfnWndProc = DemoWindowProc;
	wcl.hInstance = GetModuleHandleA(NULL);
	wcl.cbSize = sizeof(WNDCLASSEX);
	wcl.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));

	return wcl;
}


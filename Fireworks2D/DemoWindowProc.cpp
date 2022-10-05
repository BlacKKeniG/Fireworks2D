#include "DemoWindowProc.h"

LRESULT WINAPI DemoWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {

	case WM_QUIT:
	case WM_DESTROY: {
		PostQuitMessage(0);
	} return 0;

	case WM_SETCURSOR: {
		SetCursor(NULL);
	} break;

	default: {
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	} return TRUE;
}
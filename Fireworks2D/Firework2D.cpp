
#include <thread>

#include "Simulator.h"

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow) {

	Simulator fireworks2D;

	MSG message{};
	BOOL run{ true };

	while (run) {

		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
			if (message.message == WM_QUIT || message.wParam == VK_ESCAPE) {
				run = false;
			}
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		fireworks2D.run();

		std::this_thread::sleep_for(std::chrono::milliseconds(FPS));
	}
	return 0;
}
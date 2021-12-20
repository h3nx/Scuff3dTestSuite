#include "Game/Game.h"
#include "Utils/Development/ConsoleOutput.h"
#include "Utils/Development/Misc.h"
#include "Settings/Settings.h"
//#include <sysinfoapi.h>
#include <memory>

using namespace scuff3d;

LRESULT CALLBACK    mainWindowProc(HWND, UINT, WPARAM, LPARAM);
Game* application;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {

	logMemLeaks();
#ifdef _DEBUG

	initConsole();
#endif

	application = new Game(hInstance, mainWindowProc);
	if (!application) {
		return 1;
	}

	MSG msg = { 0 };
	while (application->isRunning()) {

		while (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		application->Frame();
	}


	delete application;

#ifdef _DEBUG
	releaseConsole(false);

#endif
	return 0;
}

LRESULT CALLBACK mainWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	if (application)
		if (application->wndProc(hWnd, message, wParam, lParam) == 0)
			return 0;

	switch (message) {

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_MOVING:
	case WM_SIZING:
		/*if (application) {
			application->Frame();
		}*/
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;

}


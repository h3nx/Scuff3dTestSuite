#include "Game/Game.h"
#include "Utils/Development/ConsoleOutput.h"
#include "Settings/Settings.h"
//#include <sysinfoapi.h>
#include <memory>

using namespace scuff3d;

LRESULT CALLBACK    mainWindowProc(HWND, UINT, WPARAM, LPARAM);
Game* application;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {

#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	AllocConsole();
	FILE* a;
	freopen_s(&a, "CONIN$", "r", stdin);
	freopen_s(&a, "CONOUT$", "w", stdout);
	freopen_s(&a, "CONOUT$", "w", stderr);
	//DEVLOG("console init : " + std::to_string((float)((end.QuadPart - start.QuadPart) * 1.0 / frequency.QuadPart)) + "s");
#endif

	application = new Game(hInstance, mainWindowProc);
	if (!application) {
		return 1;
	}

	//DEVLOG("main application init : " + std::to_string((float)((end.QuadPart - start.QuadPart) * 1.0 / frequency.QuadPart)) + "s");

	MSG msg = { 0 };
	while (application->isRunning()) {

		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			application->Frame();
		}
	}


	delete application;

#ifdef _DEBUG
	system("pause");
	FreeConsole();
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
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;

}


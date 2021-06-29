#pragma once
#include "Application.h"
//#include "imgui/imgui.h"
class Game :
	public scuff3d::Application {
public:

	Game();
	Game(HWND hwnd);
	Game(HINSTANCE hInstance, WNDPROC wndProc);
	~Game();
	void exit();

	void Frame();

	float beginFrame();

	void preUpdate();
	void update();
	void postUpdate();

	bool preFixedUpdate();
	bool fixedUpdate();
	bool postFixedUpdate();

	void preRender();
	void render();
	void postRender();

	void endFrame();



private:





};


#pragma once
#include "Application.h"
#include "Scuff3dImGui/Window/Scuff3dImGuiWindow.h"

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
	void fixedUpdate();
	void postFixedUpdate();

	bool preRender();
	void render();
	void present();

	void endFrame();




	void renderImGui();



private:

	std::unique_ptr<scuff3d::Scuff3dImGuiWindow> m_statusWindow;
	void renderStatus();


};


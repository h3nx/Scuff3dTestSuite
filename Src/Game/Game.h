#pragma once
#include "Application.h"
#include "Scuff3dImGui/Window/Scuff3dImGuiWindow.h"
#include "Rendering/API/Geometry/TransformData.h"

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

	void renderImGui();



private:

	std::unique_ptr<scuff3d::Scuff3dImGuiWindow> m_statusWindow;
	std::unique_ptr<scuff3d::Scuff3dImGuiWindow> m_devWindow;
	void renderStatus();
	void renderDev();

	scuff3d::TransformData temp;


};


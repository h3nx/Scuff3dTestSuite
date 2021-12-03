#include "Game.h"
#include "Utils/Development/ConsoleOutput.h"
#include <stdlib.h>
#include "Scuff3dImGui/extensions.h"
#include "Scuff3dImGui/Widgets/RenderingAPIWidgets.h"
#include "Scuff3dImGui/Widgets/GlmWidgets.h"
//#include "Scuff3dImGui/extensions.h"
#include "Scenes/MainMenu.h"
#include "Utils/Helpers.h"

#include "Scenes/TestScene.h"

using namespace scuff3d;


Game::Game() : Application::Application()
{


}

Game::Game(HWND hwnd) : Application::Application() {

}

Game::Game(HINSTANCE hInstance, WNDPROC wndProc) : Game::Game()
{
	bool fullscreen = (bool)m_basicSettings->readInt("window fullscreen", 0);
	if (fullscreen) {

		createWindow(hInstance, wndProc, "scuff3d Test Suite");
	}
	else {
		glm::ivec2 windowPos = {
			m_basicSettings->readInt("window pos x", 500),
			m_basicSettings->readInt("window pos y", 300)
		};

		glm::ivec2 windowSize = {
			m_basicSettings->readInt("window size x", 1280),
			m_basicSettings->readInt("window size y", 720)
		};

		bool maximised = (bool)m_basicSettings->readInt("window maximised", 0);

		createWindow(hInstance, wndProc, "scuff3d Test Suite", windowSize, windowPos, maximised);
	}
	

	initRenderer(RenderingAPI::DX11);
	m_window->onClientResize("Resize viewport", 
		[&](const glm::vec2& size) {
			m_renderer->resizeRenderTarget(size);
			m_renderer->resizeViewport("standard", size);
			m_renderer->getMainCamera()->setAspectratio(size);
		}
	);

	m_window->setKeybind("MB_L", VK_LBUTTON);
	m_window->setKeybind("MB_R", VK_RBUTTON);
	m_window->setKeybind("MB_M", VK_MBUTTON);

	m_window->setKeybind("Exit", VK_ESCAPE);
	m_window->setKeybind("Forward", VK_KEY_W);
	m_window->setKeybind("Back", VK_KEY_S);
	m_window->setKeybind("Right", VK_KEY_D);
	m_window->setKeybind("Left", VK_KEY_A);
	m_window->setKeybind("Space", VK_SPACE);
	m_window->setKeybind("Down", VK_KEY_C);

	m_window->setKeybind("k1", VK_KEY_1);
	m_window->setKeybind("k2", VK_KEY_2);
	m_window->setKeybind("k3", VK_KEY_3);
	m_window->setKeybind("k4", VK_KEY_4);
	m_window->setKeybind("k5", VK_KEY_5);
	m_window->setKeybind("k6", VK_KEY_6);
	m_window->setKeybind("k7", VK_KEY_7);
	m_window->setKeybind("k8", VK_KEY_8);

	loadScene(NEW TestScene());



}

Game::~Game() {
}

void Game::exit()
{
	DEVLOG("Exiting application");

	

	 // get stuff from placement instead


	glm::ivec2 pos = m_window->getNormalPosition();
	glm::ivec2 size = m_window->getNormalSize();
	bool maximised = m_window->isMaximised();
	bool fullscreen = m_window->isFullscreen();
	m_basicSettings->write("window pos x", (int)pos.x);
	m_basicSettings->write("window pos y", (int)pos.y);
	m_basicSettings->write("window size x", (int)size.x);
	m_basicSettings->write("window size y", (int)size.y);
	m_basicSettings->write("window maximised", (int)maximised);
	m_basicSettings->write("window fullscreen", (int)fullscreen);
	Application::exit();
}

void Game::Frame()
{
	Application::Frame([&]() {renderImGui(); });
}


void Game::renderImGui()
{
	static bool showDemo = true;
	
	::ImGui::ShowDemoWindow(&showDemo);
	
	//m_statusWindow->render([&]() {renderStatus(); });
	//m_devWindow->render([&]() {renderDev(); });


}

void Game::renderStatus()
{
	/*::ImGui::Text(std::to_string(1.0f / m_dt) + " fps");

	

	if(::ImGui::BeginChild("keybinds")) {
		m_input->renderImGuiContent();
	}
	::ImGui::EndChild();*/
	
}

void Game::renderDev() {

	//scuff3dImGui::TransformDataEx(temp);
	//scuff3dImGui::Mat4(temp.getMatrixWithUpdate());

}





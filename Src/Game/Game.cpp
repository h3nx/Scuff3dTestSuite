#include "Game.h"
#include "Utils/Development/ConsoleOutput.h"
#include <stdlib.h>
#include "Scuff3dImGui/extensions.h"
//#include "Scuff3dImGui/extensions.h"

using namespace scuff3d;


Game::Game() : Application::Application(),
	m_statusWindow(new Scuff3dImGuiWindow("status window", ImVec2(0,0),ImVec2(640,360)))
{

	m_input->setKeybind("MB_L", VK_LBUTTON);
	m_input->setKeybind("MB_R", VK_RBUTTON);
	m_input->setKeybind("MB_M", VK_MBUTTON);

	m_input->setKeybind("Exit", VK_ESCAPE);
	m_input->setKeybind("Forward", VK_KEY_W);
	m_input->setKeybind("Back", VK_KEY_S);
	m_input->setKeybind("Right", VK_KEY_D);
	m_input->setKeybind("Left", VK_KEY_A);
	m_input->setKeybind("Space", VK_SPACE);

	m_input->addActionDown("Space", [&]() {DEVLOG("keybind \"event\""); });
	m_input->addActionUp("Space", [&]() {DEVLOG("Pressing Space up"); });

	m_input->addActionDown("Forward", [&]() {m_input->confineCursor(true); });
	m_input->addActionUp("Forward", [&]() {m_input->confineCursor(false); });

	m_input->addActionDown("Right", [&]() {m_input->hideCursor(true); });
	m_input->addActionUp("Right", [&]() {m_input->hideCursor(false); });


	m_input->addActionDown("Left", [&]() {m_input->lockCursor(true); });
	m_input->addActionUp("Left", [&]() {m_input->lockCursor(false); });





	m_input->removeActionUp("Space", 0);

}

Game::Game(HWND hwnd) : Application::Application() {

}

Game::Game(HINSTANCE hInstance, WNDPROC wndProc) : Game::Game()
{
	int wx = m_basicSettings->readInt("window pos x", 500);
	int wy = m_basicSettings->readInt("window pos y", 300);

	setWindow(new Window32(hInstance, wndProc, "Scuff3d Test Suite" ,glm::vec2(1280,720), glm::vec2(wx,wy)));
	initRenderer(RenderingAPI::DX11);
}

Game::~Game() {
}

void Game::exit()
{
	DEVLOG("Exiting application");
	glm::vec2 pos = m_window->getPosition();
	m_basicSettings->write("window pos x", (int)pos.x);
	m_basicSettings->write("window pos y", (int)pos.y);
	Application::exit();
}

void Game::Frame() {
	beginFrame();
	preUpdate();
	update();
	postUpdate();

	if (preFixedUpdate()) {
		fixedUpdate();
		postFixedUpdate();
	}

	if (preRender()) {
		render();
		present();
	}

	endFrame();
}

float Game::beginFrame() {
	Application::beginFrame();

	return m_dt;
}

void Game::preUpdate()
{
	Application::preUpdate();


}

void Game::update()
{
	Application::update();

	//Sleep(DWORD(0.001f * 1000.f));

}

void Game::postUpdate()
{
	Application::postUpdate();


}

bool Game::preFixedUpdate()
{
	if (!Application::preFixedUpdate())
		return false;


	return true;
}

void Game::fixedUpdate()
{
	Application::fixedUpdate();

}

void Game::postFixedUpdate()
{
	Application::postFixedUpdate();
}

bool Game::preRender()
{
	return Application::preRender();
}

void Game::render()
{	
	//std::function<void()> imgui = std::bind(&Application::renderImguiObjects, this);
	Application::render([&]() {
		renderImGui();
	});
}

void Game::present()
{
	Application::present();
}



void Game::endFrame() {
	Application::endFrame();
}

void Game::renderImGui()
{
	static bool showDemo = true;
	
	ImGui::ShowDemoWindow(&showDemo);
	
	m_statusWindow->render([&]() {renderStatus(); });

}

void Game::renderStatus()
{
	ImGui::Text(std::to_string(1.0f / m_dt) + " fps");

	

	if(ImGui::BeginChild("keybinds")) {
		m_input->renderImGuiContent();
	}
	ImGui::EndChild();
	
}

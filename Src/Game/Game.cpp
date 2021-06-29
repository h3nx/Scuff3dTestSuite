#include "Game.h"
#include "Utils/Development/ConsoleOutput.h"
#include <stdlib.h>

using namespace scuff3d;


Game::Game() : Application::Application()
{
}

Game::Game(HWND hwnd) : Application::Application() {

}

Game::Game(HINSTANCE hInstance, WNDPROC wndProc) : Game::Game()
{
	int wx = m_basicSettings->readInt("window pos x", 500);
	int wy = m_basicSettings->readInt("window pos y", 300);

	setWindow(new Window32(hInstance, wndProc, "Scuff3d Test Suite" ,glm::vec2(1280,720), glm::vec2(wx,wy)));
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

	preFixedUpdate();
	fixedUpdate();
	postFixedUpdate();

	preRender();
	render();
	postRender();


	endFrame();
}

float Game::beginFrame() {
	Application::beginFrame();

	static float accSec = 0;
	static float accHalfSec = 0;
	accSec += m_dt;
	accHalfSec += m_dt;

	if (accHalfSec >= 0.5f) {
		m_window->setWindowTitle("Scuff3d Test Suite " + std::to_string(1.0f/m_dt) + "fps");
		accHalfSec = 0.0f;
	}
	if (accSec >= 1.0f) {
		accSec = 0;
		//m_window->getRect();
	}
	Application::endFrame();
	//DEVLOG("GameBegin");
	return m_dt;
}

void Game::preUpdate()
{
	Application::preUpdate();


}

void Game::update()
{
	Application::update();

	Sleep(DWORD(0.001f * 1000.f));

}

void Game::postUpdate()
{
	Application::postUpdate();


}

bool Game::preFixedUpdate()
{
	if (!Application::fixedUpdate())
		return false;


	return true;
}

bool Game::fixedUpdate()
{
	if (!Application::fixedUpdate())
		return false;


	return true;
}

bool Game::postFixedUpdate()
{
	if (!Application::postFixedUpdate())
		return false;


	return true;
}

void Game::preRender()
{
	Application::preRender();
}

void Game::render()
{
	Application::render();
}

void Game::postRender()
{
	Application::postRender();
}



void Game::endFrame() {
	Application::endFrame();
}

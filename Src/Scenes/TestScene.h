#pragma once
#include "Scene.h"


class TestScene : public scuff3d::Scene
{
public:
	TestScene();
	~TestScene();

	bool init();

	void update(const float dt);
	void render();




private:

};

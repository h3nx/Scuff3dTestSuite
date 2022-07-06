#pragma once
#include "Scene.h"


class SplashScreen : public scuff3d::Scene
{
public:
	SplashScreen() : Scene("SplashScreen") {}
	~SplashScreen() {}

	bool init();

	void update(const float dt);
	void render();




private:

};

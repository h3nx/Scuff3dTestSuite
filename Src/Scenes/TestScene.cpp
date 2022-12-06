#include "TestScene.h"
#include "Objects/Object.h"
#include "Objects/Components.h"
#include "Objects/Systems/CameraControllerSystem.h"
#include "Objects/Systems/BasicPhysicsSystem.h"

using namespace scuff3d;

TestScene::TestScene() : Scene("TestScene"){
	
}

TestScene::~TestScene() {
}

bool TestScene::init() {


	Renderer* renderer = m_app->getRenderer();
	ModelData* cubeModel = renderer->getModel("Cube");
	ModelData* cubeScuffedModel = renderer->getModel("CubeScuffed");
	ModelData* docModel = renderer->getModel("Doc");

	GameObject* cameraObj = createObject("Camera");
	CameraData* camData = cameraObj->addComponent<Camera>();
	renderer->setMainCamera(camData);
	camData->setFovHorizontal(110);
	camData->setAspectratio(m_app->getWindow()->getClientSize());
	cameraObj->addComponent<CameraController>(m_app->getInput());





	GameObject* last = nullptr;
	for (int i = 0; i < 5; i++) {
		last = createObject("test object " + std::to_string(i), nullptr, glm::vec3((i * 3.0f) - (5.0f * 3.0f / 2.0f), 2.0f, -3.0f));
		last->addComponent<Model>(cubeModel);
	}

	last = nullptr;
	for (int i = 0; i < 5; i++) {
		last = createObject("doc " + std::to_string(i), nullptr, glm::vec3(((i-2) * 3.0f), -1.0f, -3.0f));
		last->addComponent<Animator>();
		last->addComponent<Model>(docModel);
		//last->addComponent<BasicPhysics>()->m_rotationalVelocity = { 0.0f,6.28f,0.0f };
		last->addComponent<BasicPhysics>()->setAngularVelocity({ 0.0f,((i - 2) * 3.0f),0.0f });
	}


	addSystem(NEW CameraControllerSystem());
	addSystem(NEW BasicPhysicsSystem());

	return true;
}

void TestScene::update(const float dt) {
	Scene::update(dt);


}

void TestScene::render() {
	Scene::render();

}

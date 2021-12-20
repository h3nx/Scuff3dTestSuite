#include "TestScene.h"
#include "Objects/Object.h"
#include "Objects/Components.h"

using namespace scuff3d;

TestScene::TestScene() : Scene("TestScene"){
	
}

TestScene::~TestScene() {
}

bool TestScene::init() {

	ResourceManager* rm = m_app->getResourceManager();

	rm->loadFBX("Doc", "../Scuff3d/Resources/BasicModels/Doc.fbx");

	rm->loadObj("CubeScuffed","../Scuff3d/Resources/BasicModels/Cube.obj");
	rm->addFile("Cube", "MeshFactory", Mesh::CreateCube());

	Renderer* renderer = m_app->getRenderer();
	renderer->loadShader("VertexNormalColor", "../Scuff3d/Resources/DefaultShaders/VertexNormalColor.hlsl", SHADER_TYPE::VERTEX_SHADER);
	renderer->loadShader("PixelNormalColor", "../Scuff3d/Resources/DefaultShaders/PixelNormalColor.hlsl", SHADER_TYPE::PIXEL_SHADER);
	
	renderer->loadShader("VertexColor", "../Scuff3d/Resources/DefaultShaders/VertexColor.hlsl", SHADER_TYPE::VERTEX_SHADER);
	renderer->loadShader("PixelColor", "../Scuff3d/Resources/DefaultShaders/PixelColor.hlsl", SHADER_TYPE::PIXEL_SHADER);

	renderer->loadShader("Vertex", "../Scuff3d/Resources/DefaultShaders/Default/Vertex.hlsl", SHADER_TYPE::VERTEX_SHADER);
	renderer->loadShader("Pixel", "../Scuff3d/Resources/DefaultShaders/Default/Pixel.hlsl", SHADER_TYPE::PIXEL_SHADER);

	ModelData* model = renderer->createModel("Cube", rm->getMesh("Cube"), "VertexColor", "PixelColor");
	ModelData* modelScuffed = renderer->createModel("CubeScuffed", rm->getMesh("CubeScuffed"), "VertexNormalColor", "PixelNormalColor");

	ModelData* modelDoc = renderer->createModel("Doc", rm->getMesh("Doc"), "VertexNormalColor", "PixelNormalColor");


	GameObject* editorCamera = addObject(new GameObject("Editor Camera"));
	CameraData* camData = editorCamera->addComponent<Camera>();
	m_app->getRenderer()->setMainCamera(camData);
	camData->setFovHorizontal(110);
	camData->setAspectratio(m_app->getWindow()->getClientSize());
	editorCamera->addComponent<CameraController>(m_app->getInput());

	GameObject* last = nullptr;
	for (int i = 0; i < 5; i++) {
		last = addObject(new GameObject("test object " + std::to_string(i), glm::vec3((i*3.0f)-(5.0f*3.0f/2.0f),2.0f,-3.0f)));
		last->addComponent<Animator>();
		last->addComponent<Model>(model);
		//,last?last->getComponent<Transform>():nullptr);
	}

	last = nullptr;
	for (int i = 0; i < 5; i++) {
		last = addObject(new GameObject("test object scuffed " + std::to_string(i), glm::vec3(((i-2) * 3.0f), -1.0f, -3.0f)));
		last->addComponent<Animator>();
		last->addComponent<Model>(modelDoc);
		//last->addComponent<BasicPhysics>()->m_rotationalVelocity = { 0.0f,6.28f,0.0f };
		last->addComponent<BasicPhysics>()->m_rotationalVelocity = { 0.0f,((i - 2) * 3.0f),0.0f };
		//,last?last->getComponent<Transform>():nullptr);
	}


	return true;
}

void TestScene::update(const float dt) {
	Scene::update(dt);


}

void TestScene::render() {
	Renderer* renderer = m_app->getRenderer();
	for (auto& pair : m_gameObjects) {
		GameObject* object = pair.second;
		Model* model = object->getComponent<Model>();
		Transform* transform = object->getComponent<Transform>();
		if (model) {
			renderer->renderSolid(model->getData(), transform->getMatrix());
		}



	}


}

#include "pch.h"
#include "SplashScreen.h"
#include "TestScene.h"

using namespace scuff3d;

bool SplashScreen::init()
{
	ResourceManager* rm = m_app->getResourceManager();

	rm->loadFBX("Doc", "../Scuff3d/Resources/BasicModels/Doc.fbx");

	rm->loadObj("CubeScuffed", "../Scuff3d/Resources/BasicModels/Cube.obj");
	rm->addFile("Cube", "MeshFactory", Mesh::CreateCube());
	rm->loadObj("Sphere", "../Scuff3d/Resources/BasicModels/Sphere.obj");


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

	ModelData* sphere = renderer->createModel("Sphere", rm->getMesh("Sphere"), "VertexColor", "pixelColor");

	createObject("potato test");
	createObject("potato2 test");
	createObject("potato3 test");




	m_app->clearScenes();
	m_app->loadScene(NEW TestScene());


	return true;
}

void SplashScreen::update(const float dt) {
}

void SplashScreen::render() {
}






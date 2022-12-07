#include "framework.h"
#include "SolarScene.h"

SolarScene::SolarScene()
{
	_sun = make_shared<Texture>(L"SolarSystem/sun.png", Vector2(100, 100));
	_earth = make_shared<Texture>(L"SolarSystem/earth.png", Vector2(50, 50));
	_moon = make_shared<Texture>(L"SolarSystem/moon.png", Vector2(10, 10));


	_earth->SetParent(_sun->GetMatrix());
	_moon->SetParent(_earth->GetMatrix());

	_earth->GetPos()._x += 250;
	_moon->GetPos()._x += 25;


	_worldBuffer = make_shared<MatrixBuffer>();
	_viewBuffer = make_shared<MatrixBuffer>();
	_projectBuffer = make_shared<MatrixBuffer>();

	XMMATRIX projectionM = XMMatrixOrthographicLH(WIN_WIDTH, WIN_HEIGHT, 0.0f, 1.0f);

	_projectBuffer->SetData(projectionM);

	_worldBuffer->Update();
	_viewBuffer->Update();
	_projectBuffer->Update();
}

SolarScene::~SolarScene()
{
}

void SolarScene::Update()
{
	XMMATRIX worldS = XMMatrixScaling(1, 1, 1);
	XMMATRIX worldR = XMMatrixRotationZ(0);
	XMMATRIX worldT = XMMatrixTranslation(_worldPos.x, _worldPos.y, 0);
	XMMATRIX worldSRT = worldS * worldR * worldT;
	_worldBuffer->SetData(worldSRT);
	_worldBuffer->Update();

	XMMATRIX viewS = XMMatrixScaling(1, 1, 1);
	XMMATRIX viewR = XMMatrixRotationZ(_cameraAngle);
	XMMATRIX viewT = XMMatrixTranslation(_cameraPos.x, _cameraPos.y, 0);
	XMMATRIX viewSRT = viewS * viewR * viewT;
	_viewBuffer->SetData(viewSRT);
	_viewBuffer->Update();

	_sun->GetAngle() += 0.0001f;
	_earth->GetAngle() += 0.0001f;
	_moon->GetAngle() += 0.0001f;

	_sun->Update();
	_earth->Update();
	_moon->Update();
}

void SolarScene::Render()
{
	_worldBuffer->SetVSBuffer(0);
	_viewBuffer->SetVSBuffer(1);
	_projectBuffer->SetVSBuffer(2);

	_sun->Render();
	_earth->Render();
	_moon->Render();
}

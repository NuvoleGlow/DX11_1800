#include "framework.h"

#include "Object/GameObj/Planet.h"

#include "SolarScene.h"

SolarScene::SolarScene()
{
	_sun = make_shared<Planet>("SolarSystem/sun.png", Vector2(150, 150));
	_earth = make_shared<Planet>("SolarSystem/earth.png", Vector2(100, 100));
	_moon = make_shared<Planet>("SolarSystem/moon.png", Vector2(50, 50));

	_sunTrans = make_shared<Transform>();
	_earthTrans = make_shared<Transform>();

	_sun->Getpos().x += CENTER_X;
	_sun->Getpos().y += CENTER_Y;
	_sunTrans->GetPos().x += CENTER_X;
	_sunTrans->GetPos().y += CENTER_Y;

	_earth->SetParent(_sunTrans);
	_earthTrans->SetParent(_sunTrans);
	_earth->Getpos().x += 250;
	_earthTrans->GetPos().x += 250;

	_moon->SetParent(_earthTrans);
	_moon->Getpos().x += 100;
}

SolarScene::~SolarScene()
{
}

void SolarScene::Update()
{
	_sun->GetAngle() += 0.0005f * DELTA_TIME * 100;
	_sunTrans->GetAngle() += 0.001f * DELTA_TIME * 100;
	_earth->GetAngle() += 0.0005f * DELTA_TIME * 100;
	_earthTrans->GetAngle() += 0.001f * DELTA_TIME * 100;
	_moon->GetAngle() += 0.005f * DELTA_TIME * 100;

	_sun->Update();
	_earth->Update();
	_moon->Update();

	_sunTrans->Update();
	_earthTrans->Update();
}

void SolarScene::Render()
{
	_sunTrans->SetWorldBuffer();
	_earthTrans->SetWorldBuffer();

	_sun->Render();
	_earth->Render();
	_moon->Render();
}

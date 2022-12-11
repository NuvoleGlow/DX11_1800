#include "framework.h"
#include "SolarScene.h"

SolarScene::SolarScene()
{
	_sun = make_shared<Planet>("SolarSystem/sun.png", Vector2(150, 150));
	_earth = make_shared<Planet>("SolarSystem/earth.png", Vector2(100, 100));
	_moon = make_shared<Planet>("SolarSystem/moon.png", Vector2(50, 50));

	_sunTrans = make_shared<Transform>();
	_earthTrans = make_shared<Transform>();

	_earth->SetParent(_sunTrans);
	_earthTrans->SetParent(_sunTrans);
	_earth->Getpos()._x += 250;
	_earthTrans->GetPos()._x += 250;

	_moon->SetParent(_earthTrans);
	_moon->Getpos()._x += 100;
}

SolarScene::~SolarScene()
{
}

void SolarScene::Update()
{
	if (KEY_PRESS(0x41))
	{
		_sun->Getpos()._x -= 0.5f * DELTA_TIME * 100;
		_sunTrans->GetPos()._x -= 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(0x44))
	{
		_sun->Getpos()._x += 0.5f * DELTA_TIME * 100;
		_sunTrans->GetPos()._x += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(0x57))
	{
		_sun->Getpos()._y += 0.5f * DELTA_TIME * 100;
		_sunTrans->GetPos()._y += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(0x53))
	{
		_sun->Getpos()._y -= 0.5f * DELTA_TIME * 100;
		_sunTrans->GetPos()._y -= 0.5f * DELTA_TIME * 100;
	}


	_sun->GetAngle() += 0.0005f * DELTA_TIME * 100;
	_sunTrans->GetAngle() += 0.001f * DELTA_TIME * 100;
	_earth->GetAngle() += 0.0005f * DELTA_TIME * 100;
	_earthTrans->GetAngle() += 0.001f * DELTA_TIME * 100;
	_moon->GetAngle() += 0.005f * DELTA_TIME * 100;

	_sun->Getpos() = mousePos;
	_sunTrans->GetPos() = mousePos;

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

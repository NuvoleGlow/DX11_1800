#include "framework.h"
#include "AutoTargetScene.h"

AutoTargetScene::AutoTargetScene()
{
	_texture = make_shared<AT>("Texture/2.png", Vector2(250, 125));
	_drone = make_shared<AT>("Texture/railgun.png", Vector2(300, 125));

	_2Trans = make_shared<Transform>();

	_drone->SetParent(_2Trans);

	_texture->Getpos()._x += 990;
	_texture->Getpos()._y += 540;
	_2Trans->GetPos()._x += 990;
	_2Trans->GetPos()._y += 540;

	_drone->Getpos()._x += 75;
}

AutoTargetScene::~AutoTargetScene()
{
}

void AutoTargetScene::Update()
{
	if (KEY_PRESS(0x41))
	{
		_texture->Getpos()._x -= 0.5f * DELTA_TIME * 100;
		_2Trans->GetPos()._x -= 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(0x44))
	{
		_texture->Getpos()._x += 0.5f * DELTA_TIME * 100;
		_2Trans->GetPos()._x += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(0x57))
	{
		_texture->Getpos()._y += 0.5f * DELTA_TIME * 100;
		_2Trans->GetPos()._y += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(0x53))
	{
		_texture->Getpos()._y -= 0.5f * DELTA_TIME * 100;
		_2Trans->GetPos()._y -= 0.5f * DELTA_TIME * 100;
	}

	Vector2 v1 = mousePos - _drone->GetTransform()->GetWorldPos();
	Vector2 v2 = _drone->Getpos();

	Vector2* angle = {};
	_drone->GetAngle() = angle->GetAngle(v1, v2);

	_texture->Update();
	_drone->Update();

	_2Trans->Update();
}

void AutoTargetScene::Render()
{
	_2Trans->SetWorldBuffer();

	_texture->Render();
	_drone->Render();
}

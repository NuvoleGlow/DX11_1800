#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_rect = make_shared<RectCollider>(Vector2(100.0f, 100.0f));
	_rect->GetTransform()->GetPos() = { CENTER_X, CENTER_Y };

	_circle = make_shared<CircleCollider>(100.0f);
	_circle->GetTransform()->GetPos() = { CENTER_X, CENTER_Y };
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	if (KEY_PRESS(VK_LEFT))
	{
		_rect->GetTransform()->GetPos().x -= 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(VK_RIGHT))
	{
		_rect->GetTransform()->GetPos().x += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(VK_UP))
	{
		_rect->GetTransform()->GetPos().y += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(VK_DOWN))
	{
		_rect->GetTransform()->GetPos().y -= 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(VK_SPACE))
	{
		_rect->GetTransform()->GetAngle() += 0.005f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(VK_OEM_PLUS))
	{
		_rect->GetTransform()->GetScale().x += 1.0f * DELTA_TIME;
	}

	if (KEY_PRESS(VK_OEM_MINUS))
	{
		_rect->GetTransform()->GetScale().x -= 1.0f * DELTA_TIME;
	}

	if (_circle->IsCollision(_rect, true))
	{
		_rect->SetRED();
		_circle->SetRED();
	}
	else
	{
		_rect->SetGREEN();
		_circle->SetGREEN();
	}

	_rect->Update();
	_circle->Update();
}

void CollisionScene::Render()
{
	ImGui::SliderFloat("PosX", &_rect->GetTransform()->GetPos().x, 0, WIN_WIDTH);
	ImGui::SliderFloat("PosY", &_rect->GetTransform()->GetPos().y, 0, WIN_HEIGHT);

	_rect->Render();
	_circle->Render();
}

#include "framework.h"

#include "Object/GameObj/Fortress/Ft_Turret.h"
#include "Object/GameObj/Fortress/Ft_Bullet.h"

#include "FortressScene.h"

FortressScene::FortressScene()
{
	_turret = make_shared<Ft_Turret>();

	_target = make_shared<RectCollider>(Vector2(100.0f, 100.0f));
	_target->GetTransform()->GetPos() = { CENTER_X, CENTER_Y };
}

FortressScene::~FortressScene()
{
}

void FortressScene::Update()
{
	Vector2 temp = mousePos - _turret->GetTransform()->GetWorldPos();
	float angle = temp.Angle();
	_turret->GetTransform()->GetAngle() = angle;

	for (auto bullet : _turret->GetBullets())
	{
		if (bullet->IsCollision(_target) || _target->IsCollision(bullet->GetCollider()))
		{
			_target->SetRED();
			break;
		}
		else
		{
			_target->SetGREEN();
		}
	}

	_turret->Update();
	_target->Update();
}

void FortressScene::Render()
{
	_turret->Render();
	_target->Render();

	ImGui::SliderFloat("PosX", &_target->GetTransform()->GetPos()._x, 0, WIN_WIDTH);
	ImGui::SliderFloat("PosY", &_target->GetTransform()->GetPos()._y, 0, WIN_HEIGHT);
}

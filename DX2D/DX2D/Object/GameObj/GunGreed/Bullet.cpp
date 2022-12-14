#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
	_quad = make_shared<Quad>(L"Texture/Bullet.png", Vector2(130, 130));
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (_isActive == false)
		return;

	_quad->Update();


	if (_inControl == true)
	{
		Vector2 temp = mousePos - _quad->GetTransform()->GetWorldPos();
		float angle = temp.Angle();
		_quad->GetTransform()->GetAngle() = angle;
		_inControl = false;
	}

	_quad->GetTransform()->GetPos() += _dir * _speed * DELTA_TIME;
}

void Bullet::Render()
{
	if (_isActive == false)
		return;

	_quad->Render();
}

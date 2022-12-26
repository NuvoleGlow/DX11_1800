#include "framework.h"

#include "../Fortress/Ft_Turret.h"

#include "Ft_Bullet.h"

Ft_Bullet::Ft_Bullet()
{
	_quad = make_shared<Quad>(L"Texture/Bullet.png", Vector2(130, 130));

	_rectCollider = make_shared<RectCollider>(Vector2(100, 5));
	_rectCollider->GetTransform()->SetParent(_quad->GetTransform());
}

Ft_Bullet::~Ft_Bullet()
{
}

void Ft_Bullet::Update()
{
	if (_isActive == false)
	{
		_lastTime = RUN_TIME;
		return;
	}
	else
	{
		_curTime = RUN_TIME;
	}

	if (_curTime - _lastTime > _delay)
	{
		_lastTime = 0.0;
		_curTime = 0.0;
		_isActive = false;
	}

	_quad->Update();

	_quad->GetTransform()->GetPos() += _dir * _speed * DELTA_TIME;
	_dir._y -= 0.000098f;

	if (_quad->GetTransform()->GetAngle() < PI * 0.5f || _quad->GetTransform()->GetAngle() > PI * 1.5f)
	{
		_quad->GetTransform()->GetAngle() -= 0.000098f;
	}
	else
	{
		_quad->GetTransform()->GetAngle() += 0.000098f;
	}
	_rectCollider->Update();
}

void Ft_Bullet::Render()
{
	if (_isActive == false)
		return;

	_quad->Render();
}

bool Ft_Bullet::IsCollision(shared_ptr<Ft_Turret> player)
{
	return _rectCollider->IsCollision(player->GetCollider());
}

bool Ft_Bullet::IsCollision(shared_ptr<Collider> rect)
{
	return _rectCollider->IsCollision(rect);
}
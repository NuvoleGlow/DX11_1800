#include "framework.h"

#include "../GunGreed/Player.h"
#include "../GunGreed/Gun.h"

#include "Bullet.h"

Bullet::Bullet()
{
	_quad = make_shared<Quad>(L"Texture/Bullet.png", Vector2(130, 130));

	_circleCollider = make_shared<CircleCollider>(5);
	_circleCollider->GetTransform()->SetParent(_quad->GetTransform());
	_circleCollider->GetTransform()->GetPos()._x += 60;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
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

	_quad->GetTransform()->GetPos() += _dir * _speed * DELTA_TIME;

	_quad->Update();
	_circleCollider->Update();
}

void Bullet::Render()
{
	if (_isActive == false)
		return;

	_quad->Render();
}

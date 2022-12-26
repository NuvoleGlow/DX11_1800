#include "framework.h"

#include "../Fortress/Ft_Bullet.h"

#include "Ft_Turret.h"

Ft_Turret::Ft_Turret()
{
	_quad = make_shared<Quad>(L"Texture/turret.png", Vector2(200,75));
	_quad->GetTransform()->GetPos() = Vector2(CENTER_X, CENTER_Y);

	_rectCollider = make_shared<RectCollider>(Vector2(200, 75));
	_rectCollider->GetTransform()->SetParent(_quad->GetTransform());

	_muzzle = make_shared<Transform>();
	_muzzle->SetParent(_quad->GetTransform());
	_muzzle->GetPos()._x += 75.0f;

	for (int i = 0; i < 3; i++)
	{
		shared_ptr<Ft_Bullet> bullet = make_shared<Ft_Bullet>();
		bullet->_isActive = false;
		_bullets.push_back(bullet);
	}
}

Ft_Turret::~Ft_Turret()
{
}

void Ft_Turret::Update()
{
	Input();
	_quad->Update();
	_rectCollider->Update();
	_muzzle->Update();
	for (auto bullet : _bullets)
	{
		bullet->Update();
	}
}

void Ft_Turret::Render()
{
	_quad->Render();
	for (auto bullet : _bullets)
	{
		bullet->Render();
	}
}

void Ft_Turret::FireBullet()
{
	Vector2 dir = _muzzle->GetWorldPos() - _quad->GetTransform()->GetWorldPos();

	auto iter = std::find_if(_bullets.begin(), _bullets.end(), [](const shared_ptr<Ft_Bullet>& bullet) -> bool
		{
			if (bullet->_isActive == false)
				return true;
			return false;
		});

	if (iter != _bullets.end())
	{
		(*iter)->_isActive = true;
		(*iter)->GetTransform()->GetPos() = _muzzle->GetWorldPos();
		(*iter)->SetDir(dir);
		(*iter)->GetTransform()->GetAngle() = dir.Angle();
	}
	else
	{
		// 예외처리
	}
}

void Ft_Turret::Input()
{
	if (KEY_PRESS('A'))
	{
		_quad->GetTransform()->GetPos()._x -= _speed * DELTA_TIME;
	}
	if (KEY_PRESS('D'))
	{
		_quad->GetTransform()->GetPos()._x += _speed * DELTA_TIME;
	}
	if (KEY_PRESS('W'))
	{
		_quad->GetTransform()->GetPos()._y += _speed * DELTA_TIME;
	}
	if (KEY_PRESS('S'))
	{
		_quad->GetTransform()->GetPos()._y -= _speed * DELTA_TIME;
	}
	if (KEY_PRESS(VK_UP))
	{
		_quad->GetTransform()->GetAngle() += 0.5 * DELTA_TIME;
	}
	if (KEY_PRESS(VK_DOWN))
	{
		_quad->GetTransform()->GetAngle() -= 0.5 * DELTA_TIME;
	}
	if (KEY_PRESS(VK_SPACE))
	{
		FireBullet();
	}
}

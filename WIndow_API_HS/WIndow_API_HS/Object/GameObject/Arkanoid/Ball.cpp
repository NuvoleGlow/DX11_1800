#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_ball = make_shared<CircleCollider>(Vector2(CENTER_X, 400), 10.0f);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	if (_ball->GetCenter()._y >= 500)
	{
		SetActive(false);
	}

	if (_isActive == false)
		return;

	_ball->Update();

	Vector2 now = _ball->GetCenter();
	now += _dir.Normallize() * _speed;
	_ball->SetCenter(now);


	if (_ball->GetCenter()._y <= 65)
	{
		_dir._y *= -1.0f;
	}

	if (_ball->GetCenter()._x >= 840 || _ball->GetCenter()._x <= 440)
	{
		_dir._x *= -1.0f;
	}
}

void Ball::Render(HDC hdc)
{
	_ball->Render(hdc);
}

void Ball::Fire(Vector2 dir)
{
	_dir = dir;
}

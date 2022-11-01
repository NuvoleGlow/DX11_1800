#include "framework.h"
#include "Canon.h"

Canon::Canon()
{
	_body = make_shared<CircleCollider>(Vector2(CENTER_X, CENTER_Y), 30);
	_barrel = make_shared<Barrel>();
	_barrel->_startPos = _body->GetCenter();
	_barrel->_endPos = _barrel->_startPos + Vector2(_barrelSize, 0);
	_bullet = make_shared<CircleCollider>(Vector2(_body->GetCenter()._x, _body->GetCenter()._y), 5);
}

Canon::~Canon()
{
}

void Canon::Update()
{
	_bullet->Update();
	_barrel->Update();
	_body->Update();

	_barrel->_startPos = _body->GetCenter();
	_barrel->_endPos._x = _body->GetCenter()._x + _barrelSize * cosf(_angle);
	_barrel->_endPos._y = _body->GetCenter()._y + _barrelSize * sinf(_angle);

	Vector2 temp = _bullet->GetCenter();
	temp._x += _bulletSpeed * cosf(_angle);
	temp._y += _bulletSpeed * sinf(_angle);
	_bullet->SetCenter(temp);
}

void Canon::Render(HDC hdc)
{
	_bullet->Render(hdc);
	_barrel->Render(hdc);
	_body->Render(hdc);
}

void Canon::MoveLeft()
{
	Vector2 temp = _body->GetCenter();
	temp._x -= _speed;
	_body->SetCenter(temp);
}

void Canon::MoveRight()
{
	Vector2 temp = _body->GetCenter();
	temp._x += _speed;
	_body->SetCenter(temp);
}

void Canon::Shoot()
{
	_bullet = make_shared<CircleCollider>(Vector2(_body->GetCenter()._x, _body->GetCenter()._y), 5);
}

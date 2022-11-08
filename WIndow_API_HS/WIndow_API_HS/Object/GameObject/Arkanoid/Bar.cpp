#include "framework.h"
#include "Bar.h"

Bar::Bar()
{
	_bar = make_shared<RectCollider>(Vector2(CENTER_X, 500), Vector2(80, 20));
}

Bar::~Bar()
{
	_bar = nullptr;
}

void Bar::Update()
{
	_bar->Update();

	if (this->IsCollision(_ball) == true)
	{
		float before_x = this->GetBar()->GetCenter()._x - _ball->GetCollider()->GetCenter()._x;
		float before_y = this->GetBar()->GetCenter()._y - _ball->GetCollider()->GetCenter()._y;

		if (_ball->GetCollider()->GetCenter()._x <= this->GetBar()->GetCenter()._x + 50 ||
			_ball->GetCollider()->GetCenter()._x >= this->GetBar()->GetCenter()._x - 50)
		{
			_ball->SetDir(Vector2(-before_x, before_y));
		}
		if (_ball->GetCollider()->GetCenter()._y >= this->GetBar()->GetCenter()._y - 20)
		{
			_ball->SetDir(Vector2(before_x, -before_y));
		}
	}
}

void Bar::Render(HDC hdc)
{
	_bar->Render(hdc);
}

void Bar::MoveLeft()
{
	Vector2 temp = _bar->GetCenter();
	temp._x -= _speed;
	_bar->SetCenter(temp);
}

void Bar::MoveRight()
{
	Vector2 temp = _bar->GetCenter();
	temp._x += _speed;
	_bar->SetCenter(temp);
}

bool Bar::IsCollision(shared_ptr<Ball> ball)
{
	if (_bar->IsCollision(ball->GetCollider()))
	{
		return true;
	}
	return false;
}

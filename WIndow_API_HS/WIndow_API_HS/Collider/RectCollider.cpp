#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider()
{
	_pens[0] = CreatePen(0, 3, RED);
	_pens[1] = CreatePen(0, 3, GREEN);
	_curPen = _pens[1];
}

RectCollider::RectCollider(Vector2 center, Vector2 size)
	: _center(center), _size(size)
{
	_pens[0] = CreatePen(0, 3, RED);
	_pens[1] = CreatePen(0, 3, GREEN);
	_curPen = _pens[1];
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	float left = _center._x - (_size._x * 0.5f);
	float right = _center._x + (_size._x * 0.5f);
	float top = _center._y - (_size._y * 0.5f);
	float bottom = _center._y + (_size._y * 0.5f);

	Rectangle(hdc, left, top, right, bottom);
}

void RectCollider::SetRED()
{
	_curPen = _pens[0];
}

void RectCollider::SetGREEN()
{
	_curPen = _pens[1];
}

bool RectCollider::IsCollision(const Vector2& pos)
{
	float left = _center._x - (_size._x * 0.5f);
	float right = _center._x + (_size._x * 0.5f);
	float top = _center._y - (_size._y * 0.5f);
	float bottom = _center._y + (_size._y * 0.5f);
	
	if ((left <= pos._x && pos._x <= right) && (top <= pos._y && pos._y <= bottom))
		return true;

	return false;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> circle)
{
	float left = _center._x - (_size._x * 0.5f);
	float right = _center._x + (_size._x * 0.5f);
	float top = _center._y - (_size._y * 0.5f);
	float bottom = _center._y + (_size._y * 0.5f);

	float nCenterX = static_cast<float>(circle->GetCenter()._x);
	float nCenterY = static_cast<float>(circle->GetCenter()._y);
	float nRadius = static_cast<float>(circle->GetRadius());

	float left_1 = left - nRadius;
	float right_1 = right + nRadius;
	float top_1 = top - nRadius;
	float bottom_1 = bottom + nRadius;

	if ((left_1 <= nCenterX && nCenterX <= right_1) && (top <= nCenterY && nCenterY <= bottom))
	{
		return true;
	}
	if ((left <= nCenterX && nCenterX <= right) && (top_1 <= nCenterY && nCenterY <= bottom_1))
	{
		return true;
	}

	if (circle->IsCollision(Vector2(left, top)) == true)
	{
		return true;
	}
	if (circle->IsCollision(Vector2(left, bottom)) == true)
	{
		return true;
	}
	if (circle->IsCollision(Vector2(right, top)) == true)
	{
		return true;
	}
	if (circle->IsCollision(Vector2(right, bottom)) == true)
	{
		return true;
	}

	return false;
}

#include "framework.h"
#include "ElliCollider.h"

ElliCollider::ElliCollider()
{
}

ElliCollider::ElliCollider(Vector2 center, Vector2 size)
	: _center(center), _size(size)
{
}

void ElliCollider::Update()
{
}

void ElliCollider::Render(HDC hdc)
{
	int left = _center._x - (_size._x / 2);
	int right = _center._x + (_size._x / 2);
	int top = _center._y - (_size._y / 2);
	int bottom = _center._y + (_size._y / 2);

	Ellipse(hdc, left, top, right, bottom);
}

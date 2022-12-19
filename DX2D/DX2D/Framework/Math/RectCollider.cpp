#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider()
{
	_type = ColliderType::RECT;
	CreateVertices();
}

RectCollider::RectCollider(Vector2 size)
	: _size(size)
{
	_type = ColliderType::RECT;
	CreateVertices();
}

RectCollider::~RectCollider()
{
}

bool RectCollider::IsCollision(Vector2 pos)
{
	if (pos._x >= this->LeftTop()._x && pos._x <= this->RightBottom()._x)
	{
		if (pos._y >= this->LeftTop()._y && pos._y <= this->RightBottom()._y)
		{
			return true;
		}
	}
	return false;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> circle)
{
	return circle->IsCollision(shared_from_this());
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	if (this->IsCollision(other->LeftTop()) == true)
	{
		return true;
	}
	if (this->IsCollision(other->RightBottom()) == true)
	{
		return true;
	}
	if (this->IsCollision(Vector2(other->LeftTop()._x, other->RightBottom()._y)) == true)
	{
		return true;
	}
	if (this->IsCollision(Vector2(other->RightBottom()._x, other->LeftTop()._y)) == true)
	{
		return true;
	}
	return false;
}

bool RectCollider::IsCollision_OBB(shared_ptr<CircleCollider> circle)
{
	float angle = this->GetTransform()->GetAngle();

	Vector2 rightBottom = { (_size._x * 0.5f) * cos(angle), (_size._y * 0.5f) * sin(angle) };
	Vector2 circleRadius = { circle->GetRadius() * cos(angle), circle->GetRadius() * sin(angle) };
	Vector2 centerLine = circle->GetTransform()->GetPos() - this->GetTransform()->GetPos();
	Vector2 lineCenter = { centerLine._x * cos(angle) , centerLine._y * sin(angle) };

	for (int i = 0; i < 4; i++)
	{
		float theta = angle + (PI * 0.5f * i);

		Vector2 unit = { cos(theta), sin(theta) };

		float rb = rightBottom.Dot(unit);
		float cr = circleRadius.Dot(unit);
		float lc = lineCenter.Dot(unit);

		if (lc <= cr + rb)
		{
			return true;
		}
	}
	return false;
}

bool RectCollider::IsCollision_OBB(shared_ptr<RectCollider> other)
{
	return false;
}


Vector2 RectCollider::LeftTop()
{
	float angle = this->GetTransform()->GetAngle();

	Vector2 leftTop = { cos(angle) * (-_size._x * 0.5f), sin(angle) * (_size._y * 0.5f) };

	return this->GetTransform()->GetPos() + leftTop;
}

Vector2 RectCollider::RightBottom()
{
	float angle = this->GetTransform()->GetAngle();

	Vector2 rightBottom = { cos(angle) * (_size._x * 0.5f), sin(angle) * (-_size._y * 0.5f) };

	return this->GetTransform()->GetPos() + rightBottom;
}

void RectCollider::CreateVertices()
{
	Vector2 halfSize = _size * 0.5f;

	_vertices.emplace_back(-halfSize._x, halfSize._y);
	
	_vertices.emplace_back(halfSize._x, halfSize._y);
	
	_vertices.emplace_back(halfSize._x, -halfSize._y);
	
	_vertices.emplace_back(-halfSize._x, -halfSize._y);
	
	_vertices.emplace_back(-halfSize._x, halfSize._y);

	Collider::CreateData();

	_colorBuffer->_data.color = { 0.0f,255.0f,0.0f,1.0f };
}

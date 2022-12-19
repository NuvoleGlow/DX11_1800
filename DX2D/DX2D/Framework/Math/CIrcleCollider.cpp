#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider()
{
	_type = ColliderType::CIRCLE;
	CreateVertices();
}

CircleCollider::CircleCollider(float radius)
	: _radius(radius)
{
	_type = ColliderType::CIRCLE;
	CreateVertices();
}

CircleCollider::~CircleCollider()
{
}

bool CircleCollider::IsCollision(Vector2 pos)
{
	if ((this->GetTransform()->GetPos() - pos).Length() <= (this->_radius))
	{
		return true;
	}
	return false;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	if ((this->GetTransform()->GetPos() - other->GetTransform()->GetPos()).Length() <= (this->_radius + other->_radius))
	{
		return true;
	}
	return false;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> rect)
{
	Vector2 rc = rect->GetTransform()->GetPos();
	Vector2 cc = this->GetTransform()->GetPos();

	Vector2 lt = rect->LeftTop();
	Vector2 rb = rect->RightBottom();
	Vector2 lb = { lt._x, rb._y };
	Vector2 rt = { rb._x, lt._y };

	if (cc._x >= lt._x - _radius && cc._x <= rb._x + _radius)
	{
		if (cc._y >= rb._y && cc._y <= lt._y)
		{
			return true;
		}
	}
	if (cc._y <= rb._y - _radius && cc._y >= lt._y + _radius)
	{
		if (cc._x >= lt._x && cc._x <= rb._x)
		{
			return true;
		}
	}
	if ((cc - lt).Length() <= _radius)
	{
		return true;
	}
	if ((cc - rb).Length() <= _radius)
	{
		return true;
	}
	if ((cc - lb).Length() <= _radius)
	{
		return true;
	}
	if ((cc - rt).Length() <= _radius)
	{
		return true;
	}
	return false;
}

bool CircleCollider::IsCollision_OBB(shared_ptr<CircleCollider> circle)
{
	return false;
}

bool CircleCollider::IsCollision_OBB(shared_ptr<RectCollider> other)
{
	return false;
}

void CircleCollider::CreateVertices()
{
	UINT vertexCount = 36;

	for (int i = 0; i < 37; i++)
	{
		Vertex_Bagic vertex;
		vertex.pos.x = _radius * cos((2 * PI * i) / 36);
		vertex.pos.y = _radius * sin((2 * PI * i) / 36);
		_vertices.push_back(vertex);
	}

	Collider::CreateData();

	_colorBuffer->_data.color = { 0.0f,255.0f,0.0f,1.0f };
}

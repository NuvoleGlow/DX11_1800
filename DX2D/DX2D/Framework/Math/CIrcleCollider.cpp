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

	return false;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	return false;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> rect)
{
	return false;
}

void CircleCollider::CreateVertices()
{
	for (double a = 0.0f; a < 2 * PI; a += 0.1f)
	{
		_vertices.emplace_back(_radius *cos(a), _radius * sin(a));
	}

	_vertices.emplace_back(_radius * cos(0.0f), _radius * sin(0.0f));

	Collider::CreateData();

	_colorBuffer->_data.color = { 0.0f,255.0f,0.0f,1.0f };
}

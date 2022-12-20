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
	Vector2 temp = rect->GetWorldSize();
	float left = rect->LeftTop()._x;
	float right = rect->RightBottom()._x;
	float top = rect->LeftTop()._y;
	float bottom = rect->RightBottom()._y;

	Vector2 center = _transform->GetWorldPos();
	float radius = GetWorldRadius();

	if (center._x >= left && center._x <= right
		&& center._y <= top + radius && center._y >= bottom - radius)
		return true;

	if (center._x >= left - radius && center._x <= right + radius
		&& center._y <= top && center._y >= bottom)
		return true;

	if (IsCollision(rect->LeftTop()) || IsCollision(rect->RightBottom())
		|| IsCollision(Vector2(left, bottom)) || IsCollision(Vector2(right, top)))
		return true;

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

float CircleCollider::GetWorldRadius()
{
	XMFLOAT4X4 matrix;
	XMStoreFloat4x4(&matrix, *_transform->GetMatrix());

	return _radius * __max(matrix._11, matrix._22);
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

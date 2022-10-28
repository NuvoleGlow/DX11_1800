#pragma once
class RectCollider
{
public:
	RectCollider();
	RectCollider(Vector2 center, Vector2 size);

	void Update();
	void Render(HDC hdc);

	void SetRED();
	void SetGREEN();

	const Vector2& GetCenter() { return _center; }
	const Vector2& GetSize() { return _size; }

	void SetCenter(const Vector2& center) { _center = center; }
	void SetSize(const Vector2& size) { _size = size; }

	bool IsCollision(const Vector2& pos);
	bool IsCollision(shared_ptr<CircleCollider> circle);

private:
	HPEN _curPen;
	HPEN _pens[2];

	Vector2 _center = Vector2();
	Vector2 _size = Vector2();

};


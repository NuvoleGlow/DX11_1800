#pragma once
class Ball;

class Block
{
public:
	Block();
	~Block();

	void Update();
	void Render(HDC hdc);
	void SetPos(const Vector2& pos) { _rectCol->SetCenter(pos); }
	const Vector2& GetBlockSize() { return _rectCol->GetSize(); }

	bool IsCollision(shared_ptr<Ball> ball);
	shared_ptr<RectCollider> GetBlock() { return _rectCol; }

	bool _isActive = false;
private:
	shared_ptr<RectCollider> _rectCol;
};
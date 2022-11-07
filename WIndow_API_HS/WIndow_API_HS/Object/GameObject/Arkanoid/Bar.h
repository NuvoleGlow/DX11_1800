#pragma once
class Ball;

class Bar
{
public:
	Bar();
	~Bar();

	void Update();
	void Render(HDC hdc);

	void MoveLeft();
	void MoveRight();

	shared_ptr<RectCollider> GetBar() { return _bar; }

	bool IsCollision(shared_ptr<Ball> ball);


private:

	float _speed = 2.5f;

	shared_ptr<RectCollider> _bar;
};


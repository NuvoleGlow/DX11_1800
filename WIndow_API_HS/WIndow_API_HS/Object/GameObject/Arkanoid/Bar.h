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
	void SetBall(shared_ptr<Ball> ball) { _ball = ball; }
	bool IsCollision(shared_ptr<Ball> ball);

private:
	shared_ptr<RectCollider> _bar;
	shared_ptr<Ball> _ball;

	float _speed = 2.5f;
};


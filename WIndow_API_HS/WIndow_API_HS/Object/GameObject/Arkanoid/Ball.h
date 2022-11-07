#pragma once

class Block;
class Map;

class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void Fire(Vector2 dir);

	bool IsActive() { return _isActive; }
	void SetActive(bool value) { _isActive = value; }

	shared_ptr<CircleCollider> GetCollider() { return _ball; }
	Vector2 GetDir() { return _dir; }
	void SetDir(Vector2 dir) { _dir = dir; }

private:

	shared_ptr<CircleCollider> _ball;

	Vector2 _dir = Vector2(0.0f, 0.0f);

	float _speed = 3.0f;
	bool _isActive = false;


};


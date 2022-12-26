#pragma once

class Ft_Turret;

class Ft_Bullet
{
public:
	Ft_Bullet();
	~Ft_Bullet();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }
	shared_ptr<Collider> GetCollider() { return _rectCollider; }

	bool IsCollision(shared_ptr<Ft_Turret> player);
	bool IsCollision(shared_ptr<Collider> rect);
	void SetDir(const Vector2& dir) { _dir = dir.Normal(); }

	bool _isActive = false;
private:
	shared_ptr<Quad> _quad;

	double		_lastTime = 0.0;
	double		_curTime = 0.0;
	double		_delay = 3.0;
	float		_speed = 500.0f;
	Vector2		_dir = Vector2();

	shared_ptr<Collider> _rectCollider;
};


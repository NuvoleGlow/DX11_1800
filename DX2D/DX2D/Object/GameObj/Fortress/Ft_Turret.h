#pragma once

class Ft_Bullet;

class Ft_Turret
{
public:
	Ft_Turret();
	~Ft_Turret();

	void Update();
	void Render();

	void FireBullet(const Vector2& mousePos);

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }
	vector<shared_ptr<Ft_Bullet>> GetBullets() { return _bullets; }
	shared_ptr<Collider> GetCollider() { return _rectCollider; }

private:
	void Input();

	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _rectCollider;
	shared_ptr<Transform> _muzzle;

	vector<shared_ptr<Ft_Bullet>> _bullets;

	float _speed = 100.0f;
};


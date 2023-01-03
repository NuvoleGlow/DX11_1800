#pragma once
class CH_Bullet
{
public:
	CH_Bullet();
	~CH_Bullet();

	void Update();
	void Render();

	void CreateAction(string state);

	shared_ptr<Transform> GetTransform() { return _transform; }
	shared_ptr<Collider> GetCollider() { return _collider; }
	shared_ptr<Sprite> GetSprite() { return _sprite; }

	void SetDir(const Vector2& dir) { _dir = dir.Normal(); }

	bool _isActive = false;
private:

	double		_lastTime = 0.0;
	double		_curTime = 0.0;
	double		_delay = 1.5;

	shared_ptr<Transform> _transform;
	shared_ptr<Sprite> _sprite;
	shared_ptr<Collider> _collider;
	shared_ptr<Action> _action;
	Vector2 _dir = Vector2();

	float _speed = 500.0f;
};

#pragma once

class CH_Bullet;

class CH_Boss
{
public:
	CH_Boss();
	~CH_Boss();

	void Update();
	void Render();
	void PostRender();

	void CreateAction(string state);

	void SetLeft();
	void SetRight();

	shared_ptr<Transform> GetTransform() { return _transform; }
	shared_ptr<Collider> GetCollider() { return _collider; }

	void Dammaged(shared_ptr<CH_Bullet> bullet);

private:

	shared_ptr<Transform> _transform;
	shared_ptr<Sprite> _sprite;
	shared_ptr<Collider> _collider;
	shared_ptr<Action> _action;

	float _speed = 150.0f;

	int _hp = 1000;
};


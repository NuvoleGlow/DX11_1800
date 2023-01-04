#pragma once
class CH_Bullet
{
public:
	CH_Bullet();
	~CH_Bullet();

	void Update();
	void Render();

	void CreateAction(string state);

	shared_ptr<Transform> GetTransform() { return _sprite->GetTransform(); }

	void SetDirection(Vector2 dir);

	bool _isActive = false;
private:

	shared_ptr<Sprite> _sprite;
	shared_ptr<Collider> _collider;
	shared_ptr<Action> _action;

	Vector2 _dir = Vector2();
	float _speed = 500.0f;
};

#pragma once
class CH_Bullet
{
public:
	CH_Bullet();
	~CH_Bullet();

	void Input();

	void Update();
	void Render();
	void PostRender();

	void CreateAction(string state);
private:

	shared_ptr<Transform> _transform;
	shared_ptr<Sprite> _sprite;
	shared_ptr<Collider> _collider;
	shared_ptr<Action> _action;

	float _speed = 150.0f;
};

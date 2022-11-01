#pragma once
class Canon
{
public:
	Canon();
	~Canon();

	void Update();
	void Render(HDC hdc);

	void MoveLeft();
	void MoveRight();
	void Shoot();


	shared_ptr<CircleCollider> GetBody() { return _body; }
	float& GetAngle() { return _angle; }

	bool _isActive = true;

private:
	shared_ptr<CircleCollider> _body;
	shared_ptr<Barrel> _barrel;
	shared_ptr<CircleCollider> _bullet;

	float _speed = 2.0f;
	float _angle = 0.0f;
	float _barrelSize = 60.0f;

	float _bulletSpeed = 5.0f;


};
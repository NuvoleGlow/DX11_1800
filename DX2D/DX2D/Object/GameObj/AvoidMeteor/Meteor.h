#pragma once
class Meteor
{
public:
	Meteor();
	~Meteor();

	void Update();
	void Render();

	void Init();

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }
	shared_ptr<Collider> GetCollider() { return _circleCollider; }

	bool IsCollisionWithPlayer(shared_ptr<Surviver> player);

	bool _isActive = true;
private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _circleCollider;

	float		_speed = 300.0f;
};

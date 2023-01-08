#pragma once

class CH_Bullet;

class CH_Player
{
public:
	enum State
	{
		IDLE = 0,
		RUN = 1,
		SHOT = 2,
		JUMP = 3
	};

	CH_Player();
	~CH_Player();

	void Input();
	void Shot();
	void Jump();
	void SetIdle();

	void Update();
	void Render();
	void PostRender();

	void CreateAction(string state);

	void SetLeft();
	void SetRight();


	shared_ptr<Transform> GetTransform() { return _transform; }
	vector<shared_ptr<CH_Bullet>> GetBullets() { return _bullets; }

private:
	State _state = State::IDLE;

	vector<shared_ptr<CH_Bullet>> _bullets;

	shared_ptr<Transform> _transform;
	shared_ptr<Transform> _firePos;
	vector<shared_ptr<Sprite>> _sprites;
	shared_ptr<Collider> _collider;
	vector<shared_ptr<Action>> _actions;

	float _speed = 150.0f;
	float _gravity = 9.8f;
	float _jump = 25.0f;
};


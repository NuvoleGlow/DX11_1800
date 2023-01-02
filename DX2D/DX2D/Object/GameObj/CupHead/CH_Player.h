#pragma once

class CH_Bullet;

class CH_Player
{
public:
	enum State
	{
		IDLE = 0,
		RUN = 1,
		SHOT = 2
	};

	CH_Player();
	~CH_Player();

	void Input();

	void Update();
	void Render();
	void PostRender();

	void CreateAction(string state);

	void SetState();

	int _stateNum = 0;

private:
	State _state = State::IDLE;

	shared_ptr<Transform> _transform;
	vector<shared_ptr<Sprite>> _sprites;
	shared_ptr<Collider> _collider;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<CH_Bullet> _bullet;

	float _speed = 75.0f;
};


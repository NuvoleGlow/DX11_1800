#pragma once
class CH_Player
{
public:
	enum State
	{
		IDLE = 0,
		RUN = 1
	};

	CH_Player();
	~CH_Player();

	void Input();

	void Update();
	void Render();
	void PostRender();

	void CreateAction(string state);

	void SetState();

private:
	State _state = State::IDLE;
	int _stateNum = 0;

	shared_ptr<Transform> _transform;
	vector<shared_ptr<Sprite>> _sprites;
	shared_ptr<Collider> _collider;
	vector<shared_ptr<Action>> _actions;

	float _speed = 30.0f;

};


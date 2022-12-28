#pragma once
class Action
{
public:
	struct Clip
	{
		Vector2 startPos;
		Vector2 size;
		shared_ptr<SRV> srv;

		Clip(float x, float y, float w, float h, shared_ptr<SRV> srv)
			: startPos(x, y)
			, size(w, h)
			, srv(srv)
		{

		}
	};

	enum Type
	{
		END,
		LOOP,
		PINGPONG
	};

	Action(vector<Clip> clips, string name = "", Type type = LOOP, float speed = 0.5f);
	~Action();

	void Update();

	void Play();
	void Pause();
	void Stop();
	void Reset();

	Clip GetCurClip() { return _clips[_curClipNum]; }
	Action::Type GetRepeatType() { return _repeatType; }

	bool _isPlay = true;

private:
	string _name;
	vector<Clip> _clips;

	Type _repeatType;

	UINT _curClipNum = 0;

	float _time = 0.0f;
	float _speed = 0.0f;

	bool _isReverse = false;

};


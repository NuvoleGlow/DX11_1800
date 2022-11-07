#pragma once
class Map
{
public:
	Map();
	~Map();

	void Update();
	void Render(HDC hdc);
	void Fire();

private:
	UINT _poolCount = 54;

	Vector2 _offset = { 460,70 };
	Vector2 _gap = { 5,5 };

	vector<shared_ptr<Block>> _blocks;
	shared_ptr<Ball> _ball;
	shared_ptr<Bar> _bar;

	shared_ptr<RectCollider> _frame;
};
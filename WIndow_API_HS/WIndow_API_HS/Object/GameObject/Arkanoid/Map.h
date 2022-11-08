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
	shared_ptr<RectCollider> _frame;
	shared_ptr<Ball> _ball;
	shared_ptr<Bar> _bar;
	vector<shared_ptr<Block>> _blocks;
	UINT _poolCount = 54;
	Vector2 _offset = { 460,70 };
	Vector2 _gap = { 5,5 };
};
#include "framework.h"
#include "Block.h"

Block::Block()
{
	_rectCol = make_shared<RectCollider>(Vector2(CENTER_X, CENTER_Y), Vector2(40, 20));
}

Block::~Block()
{
}

void Block::Update()
{
	if (_isActive == false)
		return;

	_rectCol->Update();
}

void Block::Render(HDC hdc)
{
	if (_isActive == false)
		return;

	_rectCol->Render(hdc);
}

bool Block::IsCollision(shared_ptr<Ball> ball)
{
	if (_isActive == false)
	{
		return false;
	}

	if (_rectCol->IsCollision(ball->GetCollider()))
	{
		return true;
	}

	return false;
}

#include "framework.h"
#include "Map.h"

Map::Map()
{
	_frame = make_shared<RectCollider>(Vector2(CENTER_X, 310), Vector2(410, 510));

	_bar = make_shared<Bar>();

	_ball = make_shared<Ball>();

	_blocks.reserve(_poolCount);
	// 오브젝트 풀링
	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<Block> block = make_shared<Block>();
		block->_isActive = true;
		_blocks.push_back(block);
	}

	int maxX = 9;
	int maxY = 6;
	Vector2 blockSize = _blocks[0]->GetBlockSize();

	for (int y = 0; y < maxY; y++)
	{
		for (int x = 0; x < maxX; x++)
		{
			int index = x + y * maxX; // 인덱스 공식 (2차원 배열)

			Vector2 pos;
			pos._x = blockSize._x * x + _gap._x * x;
			pos._y = blockSize._y * y + _gap._y * y;
			pos += _offset;

			_blocks[index]->SetPos(pos);
		}
	}
}

Map::~Map()
{
}

void Map::Update()
{
	_frame->Update();
	_bar->Update();
	_ball->Update();

	for (auto& block : _blocks)
		block->Update();


	for (auto& block : _blocks)
	{
		if (block->IsCollision(_ball) == true)
		{
			float before_x = _ball->GetDir()._x;
			float before_y = _ball->GetDir()._y;

			block->_isActive = false;
			if (_ball->GetCollider()->GetCenter()._x <= block->GetBlock()->GetCenter()._x + 30
				|| _ball->GetCollider()->GetCenter()._x >= block->GetBlock()->GetCenter()._x - 30)
			{
				_ball->SetDir(Vector2(-before_x, before_y));
			}
			if (_ball->GetCollider()->GetCenter()._y >= block->GetBlock()->GetCenter()._x - 20
				|| _ball->GetCollider()->GetCenter()._y <= block->GetBlock()->GetCenter()._x + 20)
			{
				_ball->SetDir(Vector2(before_x, -before_y));
			}
		}
	}

	if (_bar->IsCollision(_ball) == true)
	{
		float before_x = _bar->GetBar()->GetCenter()._x - _ball->GetCollider()->GetCenter()._x;
		float before_y = _bar->GetBar()->GetCenter()._y - _ball->GetCollider()->GetCenter()._y;

		if (_ball->GetCollider()->GetCenter()._x <= _bar->GetBar()->GetCenter()._x + 50 ||
			_ball->GetCollider()->GetCenter()._x >= _bar->GetBar()->GetCenter()._x - 50)
		{
			_ball->SetDir(Vector2(-before_x, before_y));
		}
		if (_ball->GetCollider()->GetCenter()._y >= _bar->GetBar()->GetCenter()._y - 20)
		{
			_ball->SetDir(Vector2(before_x, -before_y));
		}
		
	}

	if (GetAsyncKeyState(VK_LEFT))
		if (_bar->GetBar()->GetCenter()._x >= 480)
			_bar->MoveLeft();
		else
			return;
	if (GetAsyncKeyState(VK_RIGHT))
		if (_bar->GetBar()->GetCenter()._x <= 800)
			_bar->MoveRight();
		else
			return;

	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))
		if (_ball->IsActive() == true)
			return;
		else
			Fire();
}

void Map::Render(HDC hdc)
{
	_frame->Render(hdc);
	_bar->Render(hdc);
	_ball->Render(hdc);

	for (auto& block : _blocks)
		block->Render(hdc);
}

void Map::Fire()
{
	Vector2 dir = _bar->GetBar()->GetCenter() - _ball->GetCollider()->GetCenter();
	_ball->SetActive(true);
	_ball->Fire(dir);
}

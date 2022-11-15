#include "framework.h"
#include "MazePlayer.h"

MazePlayer::MazePlayer(shared_ptr<Maze> maze)
	: _maze(maze)
{
	_pos = _maze->GetStartPos();
	RightHand();
}

MazePlayer::~MazePlayer()
{
	_maze = nullptr;
}

void MazePlayer::RightHand()
{
	Vector2 curPos = _pos;                                         
	Vector2 destPos = _maze->GetEndPos();

	Vector2 frontDir[4] =
	{
		Vector2(0,-1),
		Vector2(-1,0),
		Vector2(0,1),
		Vector2(1,0)
	};

	_path.reserve(1000);
	while (curPos != destPos)
	{
		int newDir = (_dir - 1 + DIRCOUNT) % DIRCOUNT;

		if (Cango(curPos + frontDir[newDir]))
		{
			curPos += frontDir[newDir];
			_dir = static_cast<Dir>(newDir);

			_path.push_back(curPos);
		}

		else if (Cango(curPos + frontDir[_dir]))
		{
			curPos += frontDir[_dir];

			_path.push_back(curPos);
		}

		else
		{
			_dir = static_cast<Dir>((_dir + 1) % DIRCOUNT);
		}
	}

	stack<Vector2> s;
	vector<Vector2> temp;
	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
		{
			s.pop();
		}
		else
		{
			s.push(_path[i]);
		}
	}
	temp.push_back(_path.back());

	temp.reserve(s.size());
	while (true)
	{
		if (s.empty() == true)
			break;
		temp.push_back(s.top());
		s.pop();
	}

	std::reverse(temp.begin(), temp.end());
	_path = temp;
}

void MazePlayer::BFS()
{
	Vector2 frontDir[4] =
	{
		Vector2(0,-1),
		Vector2(-1,0),
		Vector2(0,1),
		Vector2(1,0)
	};

	Vector2 start = _maze->GetStartPos();
	Vector2 end = _maze->GetEndPos();
	vector<vector<bool>> discorvered = vector<vector<bool>>(25, vector<bool>(25, false));
	vector<vector<Vector2>> parent = vector<vector<Vector2>>(25, vector<Vector2>(25, Vector2(-1, -1)));
	queue<Vector2> q;
	q.push(start);
	discorvered[start._y][start._x] = true;

	while (true)
	{
		if (q.empty() == true)
			break;

		Vector2 here = q.front();
		q.pop();

		if (here == end)
			break;

		for (int i = 0; i < 4; i++)
		{
			Vector2 there = here + frontDir[i];

			if (discorvered[there._y][there._x] == true)
				continue;

			if (Cango(there) == false)
				continue;

			q.push(there);
			discorvered[there._y][there._x] = true;
			_maze->GetBlock(there)->Type() = MazeBlock::BlockType::BEHIND;
			parent[there._y][there._x] = here;
		}
	}

	Vector2 finder = parent[end._y][end._x];
	_path.push_back(end);
	while (true)
	{
		_path.push_back(finder);
		finder = parent[finder._y][finder._x];

		if (finder == start)
		{
			_path.push_back(start);
			break;
		}
	}

	std::reverse(_path.begin(), _path.end());
}

void MazePlayer::Dijkstra()
{
	Vector2 frontDir[8] =
	{
		Vector2(0,-1),
		Vector2(-1,0),
		Vector2(0,1),
		Vector2(1,0),

		Vector2(-1,-1),
		Vector2(1,-1),
		Vector2(-1,1),
		Vector2(1,1)
	};

	Vector2 start = _maze->GetStartPos();
	Vector2 end = _maze->GetEndPos();
	vector<vector<bool>> discorvered = vector<vector<bool>>(25, vector<bool>(25, false));
	vector<vector<Vector2>> parent = vector<vector<Vector2>>(25, vector<Vector2>(25, Vector2(-1, -1)));
	vector<vector<float>> best = vector<vector<float>>(25, vector<float>(25, 100000));
	priority_queue<Vertex_Dijkstra, vector<Vertex_Dijkstra>, greater<Vertex_Dijkstra>> pq;

	pq.push(Vertex_Dijkstra(start, 0));
	best[start._y][start._x] = 0;
	discorvered[start._y][start._x] = true;

	while (true)
	{
		if (pq.empty() == true)
			break;

		Vector2 here = pq.top().pos;
		float g = pq.top().g;
		pq.pop();

		if (here == end)
			break;

		if (best[here._y][here._x] < g)
			continue;

		for (int i = 0; i < 8; i++)
		{
			Vector2 there = here + frontDir[i];

			if (Cango(there) == false)
				continue;

			float nextG;
			if (i >= 4)
				nextG = best[here._y][here._x] + 1.4f;
			else
				nextG = best[here._y][here._x] + 1.0f;

			if (nextG >= best[there._y][there._x])
				continue;

			pq.push(Vertex_Dijkstra(there, nextG));
			discorvered[there._y][there._x] = true;
			best[there._y][there._x] = nextG;
			_maze->GetBlock(there)->Type() = MazeBlock::BlockType::BEHIND;
			parent[there._y][there._x] = here;
		}
	}

	Vector2 finder = parent[end._y][end._x];
	_path.push_back(end);
	while (true)
	{
		_path.push_back(finder);
		finder = parent[finder._y][finder._x];

		if (finder == start)
		{
			_path.push_back(start);
			break;
		}
	}

	std::reverse(_path.begin(), _path.end());
}

void MazePlayer::AStar()
{
	Vector2 frontDir[8] =
	{
		Vector2(0,-1),
		Vector2(-1,0),
		Vector2(0,1),
		Vector2(1,0),

		Vector2(-1,-1),
		Vector2(1,-1),
		Vector2(-1,1),
		Vector2(1,1)
	};

	Vector2 start = _maze->GetStartPos();
	Vector2 end = _maze->GetEndPos();
	vector<vector<bool>> discorvered = vector<vector<bool>>(25, vector<bool>(25, false));
	vector<vector<Vector2>> parent = vector<vector<Vector2>>(25, vector<Vector2>(25, Vector2(-1, -1)));
	vector<vector<float>> best = vector<vector<float>>(25, vector<float>(25, 100000));
	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;

	float h = start.Manhattan(end);
	pq.push(Vertex(start, 0, h));
	best[start._y][start._x] = h;
	discorvered[start._y][start._x] = true;

	while (true)
	{
		if (pq.empty() == true)
			break;

		Vector2 here = pq.top().pos;
		float g = pq.top().g;
		float h = pq.top().h;
		float f = g + h;
		pq.pop();

		if (here == end)
			break;

		if (best[here._y][here._x] < f)
			continue;

		for (int i = 0; i < 8; i++)
		{
			Vector2 there = here + frontDir[i];

			if (Cango(there) == false)
				continue;

			float nextG;
			float nextH = there.Manhattan(end);
			if (i >= 4)
				nextG = g + 1.4f;
			else
				nextG = g + 1.0f;

			if (nextG + nextH >= best[there._y][there._x])
				continue;

			pq.push(Vertex(there, nextG, nextH));
			discorvered[there._y][there._x] = true;
			best[there._y][there._x] = nextG + nextH;
			_maze->GetBlock(there)->Type() = MazeBlock::BlockType::BEHIND;
			parent[there._y][there._x] = here;
		}
	}

	Vector2 finder = parent[end._y][end._x];
	_path.push_back(end);
	while (true)
	{
		_path.push_back(finder);
		finder = parent[finder._y][finder._x];

		if (finder == start)
		{
			_path.push_back(start);
			break;
		}
	}

	std::reverse(_path.begin(), _path.end());
}

void MazePlayer::Update()
{
	if (_pathIndex >= _path.size())
		return;

	if (_time >= 1.0f)
	{
		_pos = _path[_pathIndex];

		if (_pathIndex != 0)
		{
			Vector2 temp = _path[_pathIndex - 1];
			_maze->GetBlock(temp)->Type() = MazeBlock::BlockType::BEHIND;
		}

		_time = 0.0f;
		_pathIndex++;
	}

	_time += 0.2f;
}

bool MazePlayer::Cango(const Vector2& pos)
{
	if (_maze->GetBlockType(pos) == MazeBlock::BlockType::DISABLE ||
		_maze->GetBlockType(pos) == MazeBlock::BlockType::NONE)
		return false;

	return true;
}

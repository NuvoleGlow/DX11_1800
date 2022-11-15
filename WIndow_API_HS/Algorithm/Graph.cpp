#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

struct Vertex
{
	int _data;
};

vector<vector<int>> adjacent;
vector<vector<bool>> adjacent2;
vector<bool> visited;

void CreateGraph()
{
	adjacent = vector<vector<int>>(6);
	
	adjacent[0].push_back(1);
	adjacent[0].push_back(2);
	adjacent[0].push_back(4);

	adjacent[1].push_back(0);
	adjacent[1].push_back(2);

	adjacent[2].push_back(0);
	adjacent[2].push_back(1);
	adjacent[2].push_back(3);
	adjacent[2].push_back(5);

	adjacent[3].push_back(2);

	adjacent[4].push_back(0);

	adjacent[5].push_back(2);

	for (auto& vertex : adjacent[0])
	{
		if (vertex == 5)
		{
			cout << "0번 버텍스와 5번 버텍스가 이어져있습니다." << endl;
			break;
		}
	}
}

void CreateGraph2()
{
	adjacent2 = vector<vector<bool>>(6, vector<bool>(6, false));
	visited = vector<bool>(6, false);
	
	adjacent2[0][1] = true;
	adjacent2[0][2] = true;
	adjacent2[0][4] = true;

	adjacent2[1][0] = true;
	adjacent2[1][2] = true;

	adjacent2[2][0] = true;
	adjacent2[2][1] = true;
	adjacent2[2][3] = true;
	adjacent2[2][5] = true;

	adjacent2[3][2] = true;

	adjacent2[4][0] = true;

	adjacent2[5][2] = true;

	if (adjacent2[2][5] == true)
		cout << "연결되어있습니다." << endl;
}

void DFS(int start)
{
	visited[start] = true;

	int next;
	for (int i = 0; i < adjacent2.size(); i++)
	{
		if (adjacent2[start][i] == true)
		{
			if (visited[i] == true)
				continue;
			next = i;
			DFS(next);
		}
	}
}

void DFS_ALL()
{
	int count = 0;

	for (int i = 0; i < adjacent2.size(); i++)
	{
		if (visited[i] == false)
		{
			count++;
			DFS(i);
		}
	}

	cout << "뭉탱이 개수 : " << count << endl;
}

int main()
{
	CreateGraph2();

	DFS_ALL();

	return 0;
}
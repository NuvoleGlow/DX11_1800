#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

bool BinarySearch(vector<int>& v, int num)
{
	int left = 0;
	int right = 0;

	while (true)
	{
		if (left > right)
		{
			cout << "못찾았습니다." << endl;
			return false;
		}

		cout << "탐색범위 : " << left << " 부터 " << right << "까지" << endl;

		int mid = (left + right) / 2;

		if (num > v[mid])
		{
			cout << num << " > " << v[mid] << endl;
			left = mid + 1;
		}
		else if (num < v[mid])
		{
			cout << num << " < " << v[mid] << endl;
			right = mid - 1;
		}
		if (num == v[mid])
		{
			return true;
		}
		return false;
	}
}

int main()
{
	vector<int> v = { 2,10,15,30,50,80,90,120,150,200 };
	if (BinarySearch(v, 14))
	{
		cout << "찾았습니다." << endl;
	}
	return 0;
}
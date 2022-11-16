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
			cout << "��ã�ҽ��ϴ�." << endl;
			return false;
		}

		cout << "Ž������ : " << left << " ���� " << right << "����" << endl;

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
		cout << "ã�ҽ��ϴ�." << endl;
	}
	return 0;
}
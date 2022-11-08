#include <iostream>
#include <list>
#include <queue>

using namespace std;

// Queue : First Input First Out

template <typename T, typename Container = deque<T>>
class Queue
{
public:
	void push(const T& value)
	{
		q.push_front(value);
	}

	void pop()
	{
		q.pop_front();
	}

	const T& front()
	{
		return q.front();
	}

	bool empty()
	{
		return q.size() == 0;
	}

public:
	Container q;
};

int main()
{
	cout << "내가 정의한 Queue" << endl;

	Queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);

	while (true)
	{
		if (q1.empty() == true)
		{
			break;
		}

		cout << q1.front() << endl;
		q1.pop();
	}

	cout << "정의되어있는 queue" << endl;

	queue<int> q2;
	q2.push(1);
	q2.push(2);
	q2.push(3);
	q2.push(4);

	while (true)
	{
		if (q2.empty() == true)
			break;

		cout << q2.front() << endl;
		q2.pop();
	}

	return 0;
}
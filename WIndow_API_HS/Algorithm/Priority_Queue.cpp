#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <concurrent_priority_queue.h>

using namespace std;

template<typename T, typename Container = vector<T>>
class PriorityQueue
{
public:
	void push(const T& value)
	{
		_heap.push_back(value);

		int now = static_cast<int>(_heap.size()) - 1;

		while (true)
		{
			if (now <= 0)
				break;

			int parent = (now - 1) / 2;
			if ((_heap[now] > _heap[parent]))
			{
				break;
			}

			std::swap(_heap[now], _heap[parent]);
			now = parent;
		}
	}

	void pop()
	{
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int leftChild = 2 * now + 1;
			int rightChild = 2 * now + 2;

			if (leftChild >= (int)_heap.size())
				break;

			int next = now;

			if ((_heap[next] > _heap[leftChild]))
				next = leftChild;

			if (rightChild < (int)_heap.size() && (_heap[next] > _heap[rightChild]))
				next = rightChild;

			if (next == now)
				break;

			std::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	const T& top()
	{
		return _heap[0];
	}

	bool empty()
	{
		return _heap.empty();
	}

	vector<T> _heap;
};

int main()
{
	PriorityQueue<int> pq;

	pq.push(50);
	pq.push(55);
	pq.push(70);
	pq.push(37);
	pq.push(10);
	pq.push(45);
	pq.push(3);

	pq.pop();

	cout << pq.top() << endl;

	return 0;
}
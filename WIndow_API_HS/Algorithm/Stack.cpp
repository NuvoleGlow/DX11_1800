#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Constructor
{
public:
	Constructor(int n) { cout << "������ ȣ��" << endl; }
	Constructor(const Constructor& c) { cout << "��������� ȣ��" << endl; }
	Constructor(Constructor&& c) { cout << "�̵������� ȣ��" << endl; }
	~Constructor() { cout << "�Ҹ��� ȣ��" << endl; }

};

// Stack : First Input Last Out

class Stack
{
public:
	void push(const int& value)
	{
		v.push_back(value);
	}

	void pop()
	{
		v.pop_back();
	}

	const int& top()
	{
		return v.back();
	}

	bool empty()
	{
		return v.size() == 0;
	}

public:
	vector<int> v;
};

int main()
{
	cout << "���� ������ Stack" << endl;

	Stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);

	while (true)
	{
		if (s1.empty() == true)
			break;

		cout << s1.top() << endl;
		s1.pop();
	}

	cout << "���ǵǾ��ִ� stack" << endl;

	stack<int> s2;
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);

	while (true)
	{
		if (s2.empty() == true)
			break;

		cout << s2.top() << endl;
		s2.pop();
	}

	return 0;
}
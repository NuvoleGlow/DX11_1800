#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

struct Node
{
	Node() {}
	Node(const string& data) : _data(data) {}

	string _data;
	vector<Node*> _children;
};

Node* CreateTree()
{
	Node* root = new Node("개발팀");
	{
		Node* node1 = new Node("프로그래밍팀");
		root->_children.push_back(node1);
		{
			Node* leaf1 = new Node("엔진");
			node1->_children.push_back(leaf1);

			Node* leaf2 = new Node("클라");
			node1->_children.push_back(leaf2);

			Node* leaf3 = new Node("서버");
			node1->_children.push_back(leaf3);
		}

		Node* node2 = new Node("기획팀");
		root->_children.push_back(node2);
		{
			Node* leaf1 = new Node("레벨디자인");
			node2->_children.push_back(leaf1);

			Node* leaf2 = new Node("밸런스");
			node2->_children.push_back(leaf2);

			Node* leaf3 = new Node("스토리");
			node2->_children.push_back(leaf3);
		}

		Node* node3 = new Node("아트팀");
		root->_children.push_back(node3);
		{
			Node* leaf1 = new Node("원화");
			node3->_children.push_back(leaf1);

			Node* leaf2 = new Node("배경");
			node3->_children.push_back(leaf2);

			Node* leaf3 = new Node("모델");
			node3->_children.push_back(leaf3);
		}
	}

	return root;
}

void PrintTree(Node* root, int deepth)
{
	for (int i = 0; i < deepth; i++)
	{
		cout << "-";
	}

	cout << root->_data << endl;

	for (auto& node : root->_children)
	{
		PrintTree(node, deepth + 1);
	}
}

int main()
{
	Node* root = CreateTree();

	return 0;
}
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree tree;

	tree.Insert(56);
	tree.Insert(90);
	tree.Insert(80);
	tree.Insert(10);
	tree.Insert(2);
	tree.Insert(120);

	tree.PrintTree(tree._root);

	cout << tree.Min(tree._root)->key << endl;

	cout << tree.Previous(tree._root)->key << endl;

	return 0;
}
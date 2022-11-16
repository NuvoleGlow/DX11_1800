#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

void BinarySearchTree::RePlace(Node* node1, Node* node2)
{
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node(key);

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	while (true)
	{
		if (node == nullptr)
			break;
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	newNode->parent = parent;

	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

void BinarySearchTree::PrintTree(Node* root)
{
	if (root == nullptr)
		return;
	
	cout << root->key << endl;
	PrintTree(root->left);
	PrintTree(root->right);
}

Node* BinarySearchTree::Search(Node* root, int key)
{
	Node* TopNode = root;
	while (true)
	{
		if (TopNode->parent == nullptr)
		{
			break;
		}
		TopNode = TopNode->parent;
	}

	Node* KeyNode = TopNode;

	while (true)
	{
		if (KeyNode->key == key)
		{
			return KeyNode;
		}

	}

	return nullptr;
}

Node* BinarySearchTree::Min(Node* root)
{
	Node* MinNode = root->left;

	while (true)
	{
		if (MinNode->left == nullptr)
		{
			break;
		}
		MinNode = MinNode->left;
	}

	return MinNode;
}

Node* BinarySearchTree::Max(Node* root)
{
	Node* MaxNode = root->right;

	while (true)
	{
		if (MaxNode->right == nullptr)
		{
			break;
		}
		MaxNode = MaxNode->right;
	}

	return MaxNode;
}

void BinarySearchTree::Delete(Node* node)
{
}

Node* BinarySearchTree::Previous(Node* node)
{
	if (node->left == nullptr)
	{
		return nullptr;
	}

	Node* PrevNode = node->left;

	while (true)
	{
		if (PrevNode->right == nullptr)
		{
			break;
		}
		PrevNode = PrevNode->right;
	}

	return PrevNode;
}

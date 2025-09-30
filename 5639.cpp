#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;

	Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class Tree
{
private:
	Node* root;

	Node* insert(Node* node, int key)
	{
		if (node == nullptr)
			return new Node(key);
		if (key < node->key)
			node->left = insert(node->left, key);
		else
			node->right = insert(node->right, key);
		return node;
	}

	void post_order(Node* node)
	{
		if (node == nullptr) return;
		post_order(node->left);
		post_order(node->right);
		cout << node->key << "\n";
	}

public:
	Tree() : root(nullptr) {}

	void insert(int key)
	{
		root = insert(root, key);
	}

	void print_post_order()
	{
		post_order(root);
	}
};

int main()
{
	Tree tree;
	int node;
	string str;

	while (1)
	{
		getline(cin, str);
		if (str.empty())
			break;
		int num = stoi(str);
		tree.insert(num);
	}

	tree.print_post_order();

	return 0;
}

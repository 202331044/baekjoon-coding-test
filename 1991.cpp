#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	char value = '.';
	Node* left;
	Node* right;

	Node(char val) : value(val), left(nullptr), right(nullptr) {}
};

class Tree
{
private:
	Node* root;

	void insert(Node* node, char p, char l, char r)
	{
		if (node == nullptr || node->value == '.')
			return;

		if (node->value == p)
		{
			node->left = new Node(l);
			node->right = new Node(r);
			return;
		}

		insert(node->left, p, l, r);
		insert(node->right, p, l, r);
	}

	void preorder(Node* node)
	{
		if (node->value == '.')
			return;
		cout << node->value;
		preorder(node->left);
		preorder(node->right);
	}

	void inorder(Node* node)
	{
		if (node->value == '.')
			return;
		inorder(node->left);
		cout << node->value;
		inorder(node->right);
	}

	void postorder(Node* node)
	{
		if (node->value == '.')
			return;
		postorder(node->left);
		postorder(node->right);
		cout << node->value;
	}

public:
	Tree()
	{
		root = new Node('A');
	}

	void insert(char p, char l, char r)
	{
		insert(root, p, l, r);
	}

	void print_preorder()
	{
		preorder(root);
		cout << "\n";
	}

	void print_inorder()
	{
		inorder(root);
		cout << "\n";
	}

	void print_postorder()
	{
		postorder(root);
		cout << "\n";
	}
};

int main()
{
	Tree tree;
	int n;
	char p, l, r;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> p >> l >> r;
		tree.insert(p, l, r);

	}

	tree.print_preorder();
	tree.print_inorder();
	tree.print_postorder();

	return 0;
}

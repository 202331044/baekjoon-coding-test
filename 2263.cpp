#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
vector<int> inorder(MAX);
vector<int> postorder(MAX);
vector<int> index(MAX);

void func(int instart, int inend, int postart, int postend)
{
	if (instart > inend || postart > postend)
		return;
	if (instart == inend)
	{
		cout << inorder[instart] << " ";
		return;
	}

	int root = postorder[postend];
	cout << root << " ";
	int mid = index[root];
	int size = mid - instart;

	func(instart, mid - 1, postart, postart + size - 1);
	func(mid + 1, inend, postart + size, postend - 1);
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> inorder[i];
		index[inorder[i]] = i;
	}

	for (int j = 0; j < n; ++j)
		cin >> postorder[j];

	func(0, n - 1, 0, n - 1);

	return 0;
}

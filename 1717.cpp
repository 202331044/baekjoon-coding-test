#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1000000;

class UnionFind
{
private:
	vector<int> parent;

public:
	UnionFind()
	{
		parent.resize(SIZE + 1);
		for (int i = 0; i <= SIZE; ++i)
			parent[i] = i;
	}

	int find(int x)
	{
		if (parent[x] == x) return x;
		else
			return parent[x] = find(parent[x]);	
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}

	void unite(int a, int b)
	{
		int tmp1 = find(a);
		int tmp2 = find(b);

		if (tmp1 != tmp2)
		{
			if (tmp1 < tmp2)
			{
				parent[tmp2] = tmp1;
				find(b);
			}	
			else
			{
				parent[tmp1] = tmp2;
				find(a);
			}	
		}
	}

	void print(int n)
	{
		for (int i = 0; i <= n; ++i)
			cout << parent[i] << " ";
		cout << "\n";
	}
};

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	int choice, a, b;
	UnionFind uf;

	cin >> n >> m;
	
	for (int i = 0; i < m; ++i)
	{
		cin >> choice >> a >> b;

		if (choice == 0)
			uf.unite(a, b);
		else
		{
			if (uf.same(a, b))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}
	return 0;
}

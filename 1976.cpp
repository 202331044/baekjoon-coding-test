#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 200;
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
		return parent[x] = find(parent[x]);
	}

	void unite(int a, int b)
	{
		int tmp1 = find(a);
		int tmp2 = find(b);
		if (tmp1 != tmp2)
		{
			if (tmp1 < tmp2)
				parent[tmp2] = tmp1;
			else
				parent[tmp1] = tmp2;
		}
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}
};

int main()
{
	vector<vector<int>> cities(201);
	vector<int> path;
	UnionFind uf;
	int n, m, tmp;

	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> tmp;
			if (tmp == 1)
				uf.unite(i, j);
		}
	}

	for (int k = 0; k < m; ++k)
	{
		cin >> tmp;
		path.push_back(tmp);
	}

	for (int l = 0; l < m - 1; ++l)
	{
		if (uf.same(path[l], path[l + 1]))
			continue;
		else
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}

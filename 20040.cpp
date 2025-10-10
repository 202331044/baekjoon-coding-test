#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 500000;

class UnionFind
{
private:
	int cnt;
	vector<int> parent;

public:
	UnionFind() : cnt(0)
	{
		parent.resize(MAX);

		for (int i = 0; i < MAX; ++i)
		{
			parent[i] = i;
		}
	}

	int find(int x)
	{
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}

	bool unite(int a, int b)
	{
		int rootA = find(a);
		int rootB = find(b);
		cnt++;

		if (rootA == rootB)
			return false;

		if (rootA < rootB)
			parent[rootB] = rootA;
		else
			parent[rootA] = rootB;
		
		return true;
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}

	int count()
	{
		return cnt;
	}
};
int main()
{
	int n, m;
	int u, v;
	UnionFind uf;
	vector<pair<int, int>> vec;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		vec.push_back({ u, v });
	}

	for (int j = 0; j < vec.size(); ++j)
	{
		auto curr = vec[j];
		u = curr.first;
		v = curr.second;

		if (uf.unite(u, v) == false)
		{
			cout << uf.count();
			return 0;
		}
	}

	cout << 0;
	return 0;
}

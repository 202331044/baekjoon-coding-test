#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10001;

class UnionFind
{
private:
	vector<int> parent;

public:
	UnionFind()
	{
		parent.resize(MAX);
		for (int i = 0; i < MAX; ++i)
			parent[i] = i;
	}

	int find(int x)
	{
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}

	void unite(int a, int b)
	{
		int rootA = find(a);
		int rootB = find(b);

		if (rootA == rootB)
			return;

		if (rootA > rootB)
			swap(rootA, rootB);
		parent[rootA] = parent[rootB] = rootA;
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}
};

long long kruskal(vector<pair<long long, pair<int, int>>>& vec)
{
	UnionFind uf;
	long long answer = 0;

	for (auto& curr : vec)
	{
		long long w = curr.first;
		int a = curr.second.first, b = curr.second.second;

		if (!uf.same(a, b))
		{
			answer += w;
			uf.unite(a, b);
		}
	}
	return answer;
}

int main()
{
	int v, e;
	int a, b;
	long long c;
	vector<pair<long long, pair<int, int>>> vec;
	cin >> v >> e;

	for (int i = 0; i < e; ++i)
	{
		cin >> a >> b >> c;
		vec.push_back({ c, {a, b} });
	}

	sort(vec.begin(), vec.end());
	cout << kruskal(vec);

	return 0;
}

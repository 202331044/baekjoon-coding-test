#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

double calcDist(pair<int, int>& a, pair<int, int>& b)
{
	return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

class UnionFind
{
private:
	vector<int> parent;
	double dist = 0;

public:
	UnionFind()
	{
		parent.resize(1001);
		for (int i = 0; i < 1001; ++i)
			parent[i] = i;
	}

	int find(int x)
	{
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}

	void unite(int a, int b, double c)
	{
		int rootA = find(a);
		int rootB = find(b);

		if (rootA == rootB)
			return;

		if (rootA > rootB)
			swap(rootA, rootB);

		dist += c;
		parent[rootB] = rootA;
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}

	double getDist()
	{
		return dist;
	}
};

int main()
{
	vector<pair<int, int>> vec;
	UnionFind uf;
	priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
	int n, m;
	int x, y, idx1, idx2;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		vec.push_back({ x ,y });
	}

	for (int j = 0; j < n - 1; ++j)
	{
		for (int k = j + 1; k < n; ++k)
		{
			pq.push({calcDist(vec[j], vec[k]), {j, k} });
		}
	}

	for (int l = 0; l < m; ++l)
	{
		cin >> idx1 >> idx2;
		idx1 -= 1;
		idx2 -= 1;

		if (uf.same(idx1, idx2) == false)
			uf.unite(idx1, idx2, 0);
	}

	while (!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();
		double c = curr.first;
		int a = curr.second.first;
		int b = curr.second.second;

		if(uf.same(a, b) == false)
			uf.unite(a, b, c);
	}

	cout << fixed << setprecision(2);
	cout << uf.getDist();
	return 0;
}

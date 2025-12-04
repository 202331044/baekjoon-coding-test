#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

class UnionFind
{
private:
	vector<int> parent;
	int size = 0;

public:
	UnionFind(int len) : size(len)
	{
		parent.resize(size);
		for (int i = 0; i < size; ++i)
			parent[i] = i;
	}

	int find(int x)
	{
		if (x == parent[x]) return x;
		return parent[x] = find(parent[x]);
	}

	void unite(int a, int b)
	{
		int pA = find(a);
		int pB = find(b);
		if (pA != pB)
		{
			if (pA > pB) swap(pA, pB);
			parent[pB] = pA;
			find(a);
			find(b);
		}
	}
};

int ccw(pii& a, pii& b, pii& c)
{
	int x1 = (b.first - a.first), y1 = (b.second - a.second);
	int x2 = (c.first - a.first), y2 = (c.second - a.second);
	int res = x1 * y2 - x2 * y1;

	if (res < 0) return -1;
	else if (res > 0) return 1;
	else return 0;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<pii>> vec(n, vector<pii>(2));
	vector<int> group(n);
	UnionFind uf(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i][0].first >> vec[i][0].second >> vec[i][1].first >> vec[i][1].second;
		group[i] = i;
	}
		
	for (int j = 0; j < n - 1; ++j)
	{
		for (int k = j + 1; k < n; ++k)
		{
			pii a, b, c, d;
			a = vec[j][0];
			b = vec[j][1];
			c = vec[k][0];
			d = vec[k][1];

			int res1 = ccw(a, b, c) * ccw(a, b, d);
			int res2 = ccw(c, d, a) * ccw(c, d, b);
			if (res1 == 0 && res2 == 0)
			{
				if (a > b) swap(a, b);
				if (c > d) swap(c, d);
				if (max(a, c) <= min(b, d))
					uf.unite(j, k);
			}
			else if (res1 <= 0 && res2 <= 0)
				uf.unite(j, k);
		}
	}

	vector<int> cnt(n, 0);
	for (int l = 0; l < n; ++l)
		cnt[uf.find(l)]++;

	int maxCnt = 0, groupSize = 0;
	for (int m = 0; m < n; ++m)
	{
		if (cnt[m] != 0)
		{
			maxCnt = max(cnt[m], maxCnt);
			groupSize++;
		}
	}

	cout << groupSize << "\n" << maxCnt;
	return 0;
}

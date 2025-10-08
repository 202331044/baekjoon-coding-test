#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 200000;

class UnionFind
{
private:
	int nextId;
	unordered_map<string, int> idMap;
	vector<int> parent;
	vector<int> networkSize;

public:
	UnionFind(): nextId(0)
	{
		parent.resize(MAX);
		networkSize.resize(MAX, 1);

		for (int i = 0; i < MAX; ++i)
			parent[i] = i;
	}

	int getId(const string& x)
	{
		if (idMap.find(x) != idMap.end())
			return idMap[x];
		else
			return idMap[x] = nextId++;
	}

	int find(int x)
	{
		if (x == parent[x]) return x;
		return parent[x] = find(parent[x]);
	}

	int unite(const string& a, const string& b)
	{
		int idA = getId(a);
		int idB = getId(b);

		int rootA = find(idA);
		int rootB = find(idB);

		if (rootA == rootB)
			return networkSize[rootA];

		if (networkSize[rootA] < networkSize[rootB])
			swap(rootA, rootB);

		parent[rootB] = rootA;
		networkSize[rootA] += networkSize[rootB];

		return networkSize[rootA];
	}
};

int main()
{
	int t, f;
	string a, b;
	cin >> t;

	while (t--)
	{
		cin >> f;
		UnionFind uf;

		for (int i = 0; i < f; ++i)
		{
			cin >> a >> b;
			cout << uf.unite(a, b) << "\n";
		}
	}
	return 0;
}

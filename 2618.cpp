#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n, w;
vector<pair<int, int>> vec(1001);
vector<vector<int>> dp(1001, vector<int>(1001, -1));

int dist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void printPath(int p1, int p2)
{
	if (p1 == w || p2 == w) return;

	int next = max(p1, p2) + 1;
	int cost1 = (p1 == 0 ? dist({ 1,1 }, vec[next]) : dist(vec[p1], vec[next]));
	int cost2 = (p2 == 0 ? dist({ n,n }, vec[next]) : dist(vec[p2], vec[next]));

	if (dp[next][p2] + cost1 < dp[p1][next] + cost2)
	{
		cout << 1 << "\n";
		printPath(next, p2);
	}
	else
	{
		cout << 2 << "\n";
		printPath(p1, next);
	}
}

int calcDP(int p1, int p2)
{
	if (p1 == w || p2 == w) return 0;
	if (dp[p1][p2] != -1) return dp[p1][p2];

	int next = max(p1, p2) + 1;
	int cost1 = (p1 == 0 ? dist({ 1, 1 }, vec[next]) : dist(vec[p1], vec[next]));
	int cost2 = (p2 == 0 ? dist({ n, n }, vec[next]) : dist(vec[p2], vec[next]));

	int res1 = cost1 + calcDP(next, p2);
	int res2 = cost2 + calcDP(p1, next);

	dp[p1][p2] = min(res1, res2);

	return dp[p1][p2];
}

int main()
{
	cin >> n >> w;

	for (int i = 1; i <= w; ++i)
		cin >> vec[i].first >> vec[i].second;

	cout << calcDP(0, 0) << "\n";
	printPath(0, 0);
    
	return 0;
}

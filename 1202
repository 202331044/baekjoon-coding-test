#include "iostream"
#include "queue"
#include "vector"
using namespace std;

struct cmp1
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.first > b.first;
	}
};

struct cmp2
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second < b.second;
	}
};

int main()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> minQue;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> maxQue;
	priority_queue<int, vector<int>, greater<int>> bagQue;

	int n, k;
	int m, v, c;
	long long result = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		minQue.push({ m,v });
	}
	for (int j = 0; j < k; j++)
	{
		cin >> c;
		bagQue.push(c);
	}

	while (bagQue.size() > 0)
	{
		int size = bagQue.top();
		bagQue.pop();
		while (minQue.size() > 0)
		{
			if (size >= minQue.top().first)
			{
				maxQue.push(minQue.top());
				minQue.pop();
			}
			else
				break;
		}
		if (maxQue.size() != 0)
		{
			result += maxQue.top().second;
			maxQue.pop();
		}
	}

	cout << result;
	return 0;
}

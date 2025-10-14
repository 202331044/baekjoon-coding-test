#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

float distance(pair<float, float>& a, pair<float, float>& b)
{
	return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

float prime(vector<pair<float, float>>& vec)
{
	float result = 0;
	vector<bool> visited(101, false);
	priority_queue <pair<float, int>, vector<pair<float ,int>>, greater<>> pq;
	pq.push({ 0.0, 0});

	while (!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();

		float dist = curr.first;
		int idx = curr.second;
		if (visited[idx] == true)
			continue;

		result += dist;
		visited[idx] = true;

		for(int i = 0; i < vec.size(); ++i)
		{
			if (visited[i] == false)
			{
				pq.push({distance(vec[idx], vec[i]), i });
			}
		}
	}
	return result;
}

int main()
{
	int n;
	float x, y;
	vector< pair<float, float>> vec;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		vec.push_back({x, y});
	}

	cout << prime(vec);
	return 0;
}

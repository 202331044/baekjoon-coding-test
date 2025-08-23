#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int>& vec, vector<long long>& res, int start, int end, long long sum)
{

	if (start >= end)
	{
		res.push_back(sum);
		return;
	}

	dfs(vec, res, start + 1, end, sum + vec[start]);
	dfs(vec, res, start + 1, end, sum);
}

int main()
{
	int n, c, tmp;
	long long cnt = 0;
	vector<int> vec;
	
	cin >> n >> c;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		vec.push_back(tmp);
	}

	vector<long long> res1, res2;

	dfs(vec, res1, 0, n / 2 , 0);
	dfs(vec, res2, n / 2, n, 0);

	sort(res1.begin(), res1.end());
	sort(res2.begin(), res2.end());

	for (auto& r : res1)
	{
		cnt += upper_bound(res2.begin(), res2.end(), c - r)- res2.begin();
	}

	cout << cnt;

	return 0;
}

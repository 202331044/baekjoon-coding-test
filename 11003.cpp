#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	deque<pair<int, int>> dq;
	int n, l;
	int num;
	cin >> n >> l;

	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		if (dq.empty())
		{
			cout << num << " ";
			if(l > 1)
				dq.push_back({ num, i });
			continue;
		}

		while (!dq.empty())
		{
			if (num <= dq.back().first)
				dq.pop_back();
			else
			{
				cout << dq.front().first << " ";
				if (dq.front().second <= i - l + 1)
					dq.pop_front();
				dq.push_back({ num, i });
				break;
			}
		}

		if (dq.empty())
		{
			cout << num << " ";
			dq.push_back({ num, i });
		}
	}
		
	return 0;
}

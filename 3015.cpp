#include "iostream"
#include "stack"
#include "utility"
using namespace std;

int main()
{
	int n, height;
	long long result = 0;

	stack<pair<int, int>> s;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		cin >> height;

		if (s.size() > 0)
		{			
			if (height > s.top().first)
			{
				do
				{
					result += s.top().second;
					s.pop();
				} while (s.size() > 0 && s.top().first < height);
			}

			if (s.size() == 0)
				s.push({ height, 1 });
			else
			{
				if (height < s.top().first)
				{
					result++;
					s.push({ height, 1 });
				}
				else
				{
					s.top().second++;
					result += s.top().second - 1;
					if (s.size() > 1)
						result++;
				}
			}	
		}
		else
			s.push({ height, 1 });
	}
	cout << result;
	return 0;
}

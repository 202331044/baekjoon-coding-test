#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, s, tmp;
	long long sum = 0;
	int length = 100001;
	int start = 0;
	vector<int> arr;
	
	cin >> n >> s;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}


	for (int end = 0; end < n; ++end)
	{
		sum += arr[end];

		while (sum >= s)
		{
			if (length > end - start + 1)
			{
				length = end - start + 1;
			}
				
			sum -= arr[start];
			start++;
		}
	}

	if (length < 100001)
		cout << length;
	else
		cout << 0;

	return 0;
}

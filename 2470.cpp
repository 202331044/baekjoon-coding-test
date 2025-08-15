#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> arr;
	int n, tmp;
	int a = 0, b = 0;
	int minVal = 2000000001;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	int left = 0, right = arr.size() - 1;

	while (left < right)
	{
		int sum = arr[left] + arr[right];

		if (sum == 0)
		{
			a = arr[left], b = arr[right];
			break;
		}
		else if (sum < 0)
		{
			if (abs(sum) < abs(minVal))
			{
				a = arr[left], b = arr[right];
				minVal = sum;
			}
			left++;
		}
		else
		{
			if (abs(sum) < abs(minVal))
			{
				a = arr[left], b = arr[right];
				minVal = sum;
			}
			right--;
		}
	}

	cout << a << " " << b;
	return 0;
}

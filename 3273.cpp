#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	int n, tmp, x;
	int result = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		vec.push_back(tmp);
	}

	cin >> x;

	sort(vec.begin(), vec.end());

	int size = vec.size();
	int left = 0, right = size - 1;

	while (left < right)
	{
		if (vec[left] + vec[right] == x)
		{
			result++;
			left++;
			right--;
			continue;
		}
			
		if (vec[left] + vec[right] < x)
			left++;
		else
			right--;
	}

	cout << result;

	return 0;
}

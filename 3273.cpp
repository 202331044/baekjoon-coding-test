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
			int leftVal = vec[left];
			int rightVal = vec[right];
			int leftCnt = 0, rightCnt = 0;

			while (left < right && vec[left] == leftVal)
			{
				left++;
				leftCnt++;
			}

			while (right >= left && vec[right] == rightVal)
			{
				right--;
				rightCnt++;
			}

			if (leftVal == rightVal)
				result += leftCnt * (leftCnt - 1)/2;
			else
				result += leftCnt * rightCnt;
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

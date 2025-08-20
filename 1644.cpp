#include <iostream>
#include <vector>

using namespace std;

int twoPointer(vector<int>& vec, int n)
{
	int start = 0, cnt = 0;
	long long sum = 0;
	int size = vec.size();

	for (int end = 0; end < size; ++end)
	{
		sum += vec[end];

		while (sum > n)
		{
			sum -= vec[start];
			start++;
		}
		
		if (sum == n)
			cnt++;
		else if (vec[end] > n)
			break;
	}

	return cnt;
}
int main()
{
	int n, tmp;
	vector<int> vec;
	vector<bool> arr(4000001, true);

	for (int i = 2; i <= 4000000; ++i)
	{
		if (arr[i] == true)
		{
			vec.push_back(i);
			tmp = i;

			while(tmp <= 4000000)
			{
				arr[tmp] = false;
				tmp += i;
			}
		}
	}

	cin >> n;
	cout << twoPointer(vec, n);

	return 0;
}

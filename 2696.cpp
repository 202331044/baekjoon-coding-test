#include "iostream"
#include "queue"
using namespace std;

int main()
{
	int* arr = new int[10000];

	int t, m, num, t_mid;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int mid;
		int cnt = 0;

		priority_queue<int> max_queue;
		priority_queue<int, vector<int>, greater<int>> min_queue;

		cin >> m;

		for (int j = 0; j < m; j++)
		{
			cin >> arr[j];
		}

		cout << (m + 1) / 2 << "\n";

		for (int k = 1; k < m + 1; k++)
		{
			if (k == 1)
			{
				mid = arr[k - 1];
				cout << mid << " ";
				cnt++;
			}
			else
			{
				if (mid < arr[k - 1])
				{
					min_queue.push(arr[k - 1]);
				}
				else if (mid >= arr[k - 1])
				{
					max_queue.push(arr[k - 1]);
				}

				if (k % 2 != 0)
				{
					t_mid = mid;
					if (min_queue.size() < max_queue.size())
					{
						mid = max_queue.top();
						max_queue.pop();
						min_queue.push(t_mid);

					}
					else if (min_queue.size() > max_queue.size())
					{
						mid = min_queue.top();
						min_queue.pop();
						max_queue.push(t_mid);
					}
					cout << mid << " ";
					cnt++;
					if (cnt % 10 == 0)
						cout << "\n";
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
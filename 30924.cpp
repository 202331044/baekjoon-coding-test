#include <iostream>
#include <random>
using namespace std;

const int MAX = 10000;
bool arrA[MAX + 1] = { false, };
bool arrB[MAX + 1] = { false, };

int main()
{
	int resp;
	bool isA = true, isB = true;
	while (isA)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(1, 10000);

		int a = dis(gen);
		if (arrA[a]) continue;

		arrA[a] = true;
		cout << "? A " << a << endl;
		cin >> resp;

		if (resp)
		{
			isA = false;
			while (isB)
			{
				int b = dis(gen);
				if (arrB[b]) continue;

				arrB[b] = true;
				cout << "? B " << b << endl;
				cin >> resp;

				if (resp)
				{
					isB = false;
					cout << "! " << a + b << endl;
				}
			}
		}
	}

	return 0;
}

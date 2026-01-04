#include <iostream>
using namespace std;

int main()
{
	int x, cnt = 0;
	int min = 1, max = 1e9;
	while (cnt < 100)
	{
		cin >> x;
		cnt++;
		if (x <= min)
			cout << ">" << endl;
		else if (x >= max)
			cout << "<" << endl;
		else
		{
			if (max - min <= 2)
			{
				cout << "=" << endl;
				break;
			}

			if (x - min > max - x)
			{
				cout << "<" << endl;
				max = x;
			}
			else
			{
				cout << ">" << endl;
				min = x;
			}		
		}
	}
	return 0;
}

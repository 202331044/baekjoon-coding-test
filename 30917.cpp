#include <iostream>
using namespace std;

int main()
{
	int resp;

	for (int i = 1; i < 10; ++i)
	{
		cout << "? A " << i << endl;
		cin >> resp;

		if (resp == 1)
		{
			int a = i;
			for (int j = 1; j < 10; ++j)
			{
				cout << "? B " << j << endl;
				cin >> resp;
				if (resp == 1)
				{
					int b = j;
					cout << "! " << a + b << endl;
					break;
				}
			}	
		}
	}
	return 0;
}

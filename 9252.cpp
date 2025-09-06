#include <iostream>
#include <string>
using namespace std;

int arr[1001][1001] = { 0, };

void dp(string& s1, string& s2)
{
	for (int i = 0; i < s1.size(); ++i)
	{
		for (int j = 0; j < s2.size(); ++j)
		{
			if (s1[i] == s2[j])
				arr[i+1][j+1] = arr[i][j] + 1;		
			else
				arr[i + 1][j + 1] = max(arr[i + 1][j], arr[i][j + 1]);
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s1, s2;
	cin >> s1 >> s2;
	
	dp(s1, s2);

	int maxLength = arr[s1.size()][s2.size()];
	cout << maxLength << "\n";

	if (maxLength != 0)
	{
		string str;
		int p1 = s1.size()-1, p2 = s2.size();
		while(p1 >= 0 && p2 >= 0)
		{
			if (s1[p1] == s2[p2])
			{
				str = s1[p1] + str;
				p1--;
				p2--;
			}
			else if (arr[p1+1][p2] > arr[p1][p2+1])
				p2--;
			else
				p1--;
		}
		cout << str;
	}

	return 0;
}

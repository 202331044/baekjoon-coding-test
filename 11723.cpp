#include <iostream>

using namespace std;

int mask;

void add(int x) { mask |= (1 << x); }
void remove(int x) { mask &= ~(1 << x); }
void check(int x) { cout << ((mask & (1 << x) ? 1 : 0)) << "\n"; }
void toggle(int x) { mask ^= 1 << x; }
void all() { mask = (1 << 21) - 1; }
void empty() { mask = 0; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, x;
	string str;
	cin >> m;

	while (m--)
	{
		cin >> str;
			
		if (str == "add")
		{
			cin >> x;
			add(x);
		}		
		else if (str == "remove")
		{
			cin >> x;
			remove(x);
		}		
		else if (str == "check")
		{
			cin >> x;
			check(x);
		}			
		else if (str == "toggle")
		{
			cin >> x;
			toggle(x);
		}	
		else if (str == "all")
			all();
		else if(str == "empty")
			empty();
	}
	return 0;
}

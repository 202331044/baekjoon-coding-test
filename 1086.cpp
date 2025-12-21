#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void computePow10Mod(vector<int>& numbers, int k)
{
	for (int i = 1; i < numbers.size(); ++i)
		numbers[i] = ((numbers[i - 1] % k) * (10 % k)) % k;
}

int computeStringMod(string& str, int k)
{
	int sum = 0;
	for (int i = 0; i < str.size(); ++i)
		sum = ((str[i] - '0') + (sum * 10)) % k;
		
	return sum;
}

ll factorial(int n)
{
	ll sum = 1;
	for (int i = 1; i <= n; ++i)
		sum *= i;

	return sum;
}

ll gcd(ll a, ll b)
{
	ll r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N;
	vector<string> numbers(N);
	for (int i = 0; i < N; ++i)
		cin >> numbers[i];
		
	cin >> K;
	vector<int> stringMod(N);
	vector<int> pow10mod(50 * 16 + 1, 1);
	vector<vector<ll>> dp((1 << N), vector<ll>(K, 0));

	dp[0][0] = 1;
	computePow10Mod(pow10mod, K);

	for (int i = 0; i < N; ++i)
		stringMod[i] = computeStringMod(numbers[i], K);

	for (int mask = 0; mask < (1 << N); ++mask)
	{
		for (int j = 0; j < N; ++j)
		{
			if (mask & (1 << j))
				continue;

			for (int rem = 0; rem < K; ++rem)
			{
				int nextRem = (rem * pow10mod[numbers[j].size()] + stringMod[j]) % K;
				dp[mask | (1 << j)][nextRem] += dp[mask][rem];
			}
		}
	}

	ll p = factorial(N);
	ll q = dp[(1 << N) - 1][0];

	if (q == 0)
	{
		p = 1;
		q = 0;
	}
	else
	{
		ll d = gcd(p, q);
		if (d == 0)
		{
			p = 1;
			q = 0;
		}
		else
		{
			p /= d;
			q /= d;
		}
	}

	cout << q << "/" << p;
	return 0;
}

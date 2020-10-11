#include <iostream>
using namespace std;
typedef long long ll;

ll power_recursive(ll A, ll N, ll mod) // A ^ N
{
	if (N == 1)
		return A % mod;

	ll ans = power_recursive(A, N/2, mod) % mod;
	ans = (ans * ans) % mod;
	return (N & 1) ? (ans * A) % mod : ans;
}

ll power_iterative(ll A, ll N, ll mod) // A ^ N
{
	ll ans = 1;
	A %= mod;

	for (; N > 0; N >>= 1)
	{
		if (N & 1)
			ans = (ans * A)	% mod;

		A = (A * A) % mod;
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);

	int a, b;

	while (true)
	{
		cin >> a >> b;
		cout << power_iterative(a, b, 1000000007) << endl;
	}

	return 0;
}

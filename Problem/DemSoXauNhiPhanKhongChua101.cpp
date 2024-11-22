#include <iostream>
using namespace std;
const long long MOD = 1000000007;

long long solve(int n)
{
	if(n == 1) return 2;
	if(n == 2) return 4;
	
	long long a[n+1][2];
	a[1][0] = a[1][1] = 1;
	a[2][0] = a[2][1] = 2;
	
	for(int i=3; i<=n; ++i)
	{
		a[i][0] = a[i-1][0] + a[i-1][1];
		a[i][0] %= MOD;
		
		a[i][1] = a[i-1][1] + a[i-2][0];
		a[i][1] %= MOD;
	}
	return (a[n][0] + a[n][1]) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n; cin >> n;
	cout << solve(n);
	
	return 0;
}

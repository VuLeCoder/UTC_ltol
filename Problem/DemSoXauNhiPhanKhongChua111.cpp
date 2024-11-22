#include <iostream>
using namespace std;
const long long MOD = 1000000007;

long long solve(int n)
{
	if(n == 1) return 2;
	if(n == 2) return 4;
	if(n == 3) return 7;
	
	long long a[n+1];
	a[1] = 2; a[2] = 4; a[3] = 7;
	for(int i=4; i<=n; ++i) 
	{
		a[i] = a[i-3] + a[i-2] + a[i-1];
		a[i] %= MOD;
	}
	return a[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n; cin >> n;
	cout << solve(n);
	
	return 0;
}

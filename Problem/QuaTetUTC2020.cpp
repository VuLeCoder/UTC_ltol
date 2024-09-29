#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string str; cin>>str;
	int n = str.length();
	long long dp[n+1];
	memset(dp, 0, sizeof(dp));
	
	if(str[0]=='0') {cout<<"0"; return 0;}
	dp[0]=1;
	
	if(str[1]=='0' && str[0]>'2') {cout<<"0"; return 0;}
	dp[1]=1;
	
	for(int i=2; i<=n; ++i)
	{
		if(str[i-1] != '0') dp[i] = dp[i-1];
		if(str[i-2] == '1' || (str[i-2] == '2' && str[i-1] <= '6'))
		{
			dp[i] += dp[i-2];
			dp[i] %= MOD;
		}
	}
	cout<<dp[n];
	return 0;
}
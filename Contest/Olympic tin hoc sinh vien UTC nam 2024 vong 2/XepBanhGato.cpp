#include <iostream>
#include <algorithm>
#include <vector>
#define t first
#define m second
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		vector< pair<long long,long long> > f(n);
		for(int i=0; i<n; ++i)
			cin>>f[i].t>>f[i].m;
		
		for(int i=1; i<n; ++i)
		{
			long long d = __gcd(f[i].m, f[i-1].m);
			long long Bc = f[i].m/d;
			Bc *= f[i-1].m;
			f[i].t *= Bc/f[i].m;
			f[i-1].t *= Bc/f[i-1].m;
			f[i].m = Bc;
			f[i].t += f[i-1].t;
			
			d = __gcd(f[i].m, f[i].t);
			f[i].m /= d;
			f[i].t /= d;
		}
		if(f[n-1].m == f[n-1].t) cout<<"YES\n";
		else cout<<"NO\n";
		
	}
	return 0;
}
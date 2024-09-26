#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(vector<pair<double, double>>& bia)
{
	int Max = 1, n = bia.size();
	int a[n];
	for(int i=0; i<n; ++i) a[i] = 1;

	for(int i=0; i<n; ++i)
		for(int j=i+1; j<n; ++j)
			if(bia[i].first < bia[j].first && bia[i].second > bia[j].second)
				a[j] = max(a[j], a[i]+1);
	
	return *max_element(a, a+n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		vector<pair<double, double>> bia(n);
		for(int i=0; i<n; ++i)
			cin>>bia[i].first>>bia[i].second;
		int res = solve(bia);
		cout<<res<<"\n";
	}
	return 0;
}
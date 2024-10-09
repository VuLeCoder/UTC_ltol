#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long n; cin>>n;
	int x = sqrt(n);
	map<int,int> mp, mp2;
	for(int i=2; i<=x; ++i)
	{
		if(n%i == 0)
		{
			while(n%i == 0)
			{
				n/=i;
				mp[i]++;
			}
		}
	}
	if(n>1) mp[n]++;
	for(auto &it : mp)
		mp2[it.second]++;
	
	if(mp2.size() == 1 && mp2[1] != 0) cout<<mp2[1];
	else
	{
		string s;
		for(auto &it : mp2)
			for(int i=0; i<it.first*it.second; ++i)
				s+=it.first + '0';
		int x = s[s.length()/2] - '0', ans = 0, i=1;
		while(x == 1)
		{
			x = s[s.length()/2 + i] - '0';
			i++;
		}

		for(auto &it : mp2)
		{
			if(it.first >= abs(it.first - x))
				ans += (abs(it.first - x) * it.second);
			else ans += it.first * it.second;
		}
		cout<<ans;
	}
    
	return 0;
}
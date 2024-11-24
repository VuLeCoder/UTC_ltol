#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
// do sau + tong_nut
unordered_map<long long, pair<long long, long long>> mp; 

void chia_doi(long long n)
{
	if(n == 1) return;
	if(n == 2) return;
	
	if(n % 2 == 0)
	{
		if(!mp.count(n/2)) chia_doi(n/2);
		
		mp[n].second = mp[n/2].second * 2 + 1;
		mp[n].first = mp[n/2].first + 1;
		return;
	}
		
	if(!mp.count((n+1)/2)) chia_doi((n+1)/2);
	if(!mp.count((n-1)/2)) chia_doi((n-1)/2);
	
	mp[n].second = mp[(n+1)/2].second + mp[(n-1)/2].second + 1;
	mp[n].first = max(mp[(n+1)/2].first, mp[(n-1)/2].first) + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	mp[1] = {1, 1};
	mp[2] = {2, 3};
	
	int t; cin >> t;
	while(t--)
	{
		long long n; cin >> n;
		if(!mp.count(n)) chia_doi(n);
		cout << mp[n].first << " " << mp[n].second << "\n";
	}
	
	return 0;
}

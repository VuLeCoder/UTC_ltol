#include <iostream>
#include <climits>
#include <cmath>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	map<int, int> mp;
	
	int n,k; cin >> n >> k;
	int a[n];
	for(int i=0; i<n; ++i) cin >> a[i], mp[a[i]]++;
	
	int m = mp.size(), j = 0;
	int arr[m];
	for(auto it : mp) arr[j] = it.first, j++;
	
//	for(int i=0; i<m; ++i) cout << arr[i] << " ";
	
	long long ans = LLONG_MAX, dist = 0;
	int l = 0, r = 0;
	int cnt = 0;
	while(r < m)
	{
		cnt += mp[arr[r]];
		
		while(cnt >= k && l <= r)
		{
			if(arr[l] < 0 && arr[r] >= 0) dist = abs(arr[l]) + abs(arr[r]) + min(abs(arr[l]), abs(arr[r]));
			else dist = max(abs(arr[l]), abs(arr[r]));
			
			ans = min(ans, dist);
			cnt -= mp[arr[l]];
			l++;
		}
		r++;
	}
	cout << ans;
	return 0;
}

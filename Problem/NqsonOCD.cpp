#include <iostream>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n; cin >> n;
	int a[n];
	for(int i=0; i<n; ++i) cin >> a[i];
	
	int l = 0, r = n-1, ans = 0;
	while(l < r)
	{
		if(a[l] == a[r]) l++, r--, ans += 2;
		else
		{
			if(a[l] < a[r]) a[l+1] += a[l], l++;
			else a[r-1] += a[r], r--;
		}
	}
	if(l == r) ans += 1;
	cout << ans;
	return 0;
}

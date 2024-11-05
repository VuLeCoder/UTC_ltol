#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	long long n,w,t; cin>>n>>w>>t;
	long long a[n];
	for(int i=0; i<n; ++i) cin>>a[i], a[i] += i;
	
	pair<long long, int> day[n];
	// day[i] : first - ngày i tổng s sẽ mất đi bao nhiêu || second - ngày i mất đi bao nhiêu ngày trc đó
	for(int i=0; i<n; ++i) day[i] = {0, 0};
	long long s = 0, ans = 0, d = 0;
	for(int i=0; i<n; ++i)
	{
		if(a[i] > t-1+i)
		{
			if(t+i < n) 
				day[t+i].first += a[i], day[t+i].second++;
		}
		else 
			if(a[i] < n)
				day[a[i]].first += a[i], day[a[i]].second++;
		
		s += a[i], d++;
		s -= day[i].first, d -= day[i].second;
		if(i >= t-1 && (s - i*d) < w)
		{
			long long diff = w - (s - i*d);
			ans += diff;
			if(a[i] > t-1+i)
			{
				if(t+i < n) 
					day[t+i].first -= a[i], day[t+i].second--;
			}
			else 
				if(a[i] < n)
					day[a[i]].first -= a[i], day[a[i]].second--;
			
			if(a[i] > i) s -= a[i];
			else d++;
			a[i] += diff;
			s+=a[i];
			
			if(a[i] > t-1+i)
			{
				if(t+i < n) 
					day[t+i].first += a[i], day[t+i].second++;
			}
			else 
				if(a[i] < n)
					day[a[i]].first += a[i], day[a[i]].second++;
		}
	}
	cout <<ans;
	
	return 0;
}

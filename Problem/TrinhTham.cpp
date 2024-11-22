#include <iostream>
#include <queue>
using namespace std;
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	priority_queue<pair<int, int>> pq;
	
	int n,k; cin >> n >> k;
	int a[n];
	for(int i=0; i<n; ++i) cin>>a[i];
	
	for(int i=0; i<k; ++i) pq.push({a[i], i});
	cout << pq.top().first << ' ';
	
	for(int i=k; i<n; ++i)
	{
		pq.push({a[i], i});
		while(pq.top().second <= i-k) pq.pop();
		cout << pq.top().first << ' ';
	}
	return 0;
}

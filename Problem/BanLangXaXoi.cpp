#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    
    int arr[n][n];
    for(int i=0; i<n; ++i)
    	for(int j=0; j<n; ++j)
    		cin >> arr[i][j];
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int res[n];
    for(int i=0; i<n; ++i)
	{
		res[i] = a[i];
		pq.push({a[i], i});
	}
	
	long long ans = 0;
    bool check[n] = {false};
	while(!pq.empty())
	{
		int u = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		
		if(check[u]) continue;
		
		check[u] = true;
		ans += cost;
		
        for(int v=0; v<n; ++v)
            if(!check[v] && arr[u][v] < res[v])
			{
                res[v] = arr[u][v];
                pq.push({res[v], v});
            }
	}
	
	cout << ans;
	return 0;
}

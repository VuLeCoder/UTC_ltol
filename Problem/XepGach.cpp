#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	int n,m; cin>>n>>m;
	vector<pair<double, int>> brick(n);
	for(int i=0; i<n; ++i)
		cin>>brick[i].second>>brick[i].first;
	
	sort(brick.begin(), brick.end());
	int arr[n] = {};
	
	for(int i=0; i<n; ++i)
	{
		arr[i] = max(arr[i], 1);
		for(int j=i+1; j<n; ++j)
			if(brick[i].second <= brick[j].second)
				arr[j] = max(arr[j], arr[i]+1);
	}
	int Min = n - *max_element(arr, arr+n);
	cout<<Min;
	return 0;
}
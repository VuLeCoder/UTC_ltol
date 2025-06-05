#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n; cin >> n;
	int a[n];
	for(int i=0; i<n; ++i) cin>>a[i];
	for(int i=0; i<n; ++i)
		if(a[i] != 0)
			cout<<a[i]<<' ';

	return 0;
}
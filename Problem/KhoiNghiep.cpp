#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n; cin >> n;
	long long X; cin >> X;
	long long maxX = 0;
	long long a[n], ans = 0;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		if(a[i] * 2 <= X) ++ans, maxX = max(maxX, a[i]);
	}
	
	for(int i=0; i<n; ++i) {
		if(a[i] * 2 <= X) continue;
		
		if(a[i] + maxX <= X) {++ans; break;}
	}
	cout << ans;
	
	return 0;
}
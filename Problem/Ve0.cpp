#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 257;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int t; cin >> t;
	int n, x, ans;
	while(t--) {
		cin >> n;
		int cnt[MAX] = {};
		for(int i=0; i<n; ++i) {
			cin >> x;
			cnt[x] = 1 - cnt[x];
		}
		
		ans = 0;
		for(int i=0; i<MAX; ++i) {
			if(cnt[i] > 0) {
				ans ^= i;
			}
		}
		
		if(ans == 0 || n % 2 != 0) {
			cout << ans << "\n";
			continue;
		}
		
		cout << "-1\n";
	}
	return 0;
}
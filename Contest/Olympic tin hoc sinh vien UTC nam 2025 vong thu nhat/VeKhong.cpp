#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int h, k; cin >> h >> k;
	int a, b, ans = 0;
	while(h * k != 0) {
		a = max(h, k);
		b = min(h, k);
		
		ans += (a / b);
		a %= b;
		h = a, k = b;
	}
	cout << ans;
	
	return 0;
}
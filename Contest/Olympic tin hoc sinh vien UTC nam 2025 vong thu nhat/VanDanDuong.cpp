#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

unsigned long long solve(unsigned long long c) {
	unsigned long long delta = 1 + 8 * c;
	return (sqrt(delta) - 1) / 2;
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	unsigned long long n; cin >> n;
	unsigned long long ans = 0;
	while(n > 0) {
		unsigned long long maxN = solve(n);
		n -= (maxN + 1) * maxN / 2;
		
		if(maxN % 2 == 0) --maxN;
		if(maxN == 1) ans += 1;
		else {
			unsigned long long ssh = (maxN - 1) / 2 + 1;
			ans += (maxN + 1) * ssh / 2;
		}
	}
	cout << ans;
	return 0;
}
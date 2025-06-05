#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<long> factors;
    for(int i=0; i<=9; ++i) {
        for(int j=max(0, i-3); j<=i+1; ++j) {
            factors.push_back(pow(2, j) * pow(5, i));
        }
    }
    sort(factors.begin(), factors.end());
    
    int t; cin >> t;
    int n, ans;
    for(int i=1; i<=t; ++i) {
        cout << "#Case " << i << ": ";
        cin >> n;
        ans = 0;
        for(int factor : factors) {
            if(factor > n) break;
            ++ans;
        }
        cout << ans << "\n";
    }

    return 0;
}

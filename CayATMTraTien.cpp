#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(const vector<int>& a, int m) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> dp(m + 1, INF);
    dp[0] = 0;
    for (int i=0; i<n; ++i) {
        for (int j=a[i]; j<=m; ++j) {
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }
    return dp[m] == INF ? -1 : dp[m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);  

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = solve(a, m);
    if (ans == -1) {
        cout << "ATM khong the tra tien";
    } else {
        cout << ans;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    int M = 10000;
    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (a[i - 1].first <= j) {
                if (dp[i - 1][j] < dp[i - 1][j - a[i - 1].first] + a[i - 1].second) {
                    dp[i][j] = dp[i - 1][j - a[i - 1].first] + a[i - 1].second;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int q; cin >> q;
    while(q--) {
        cin >> M;
        cout << dp[n][M] << "\n";
    }
    return 0;
}

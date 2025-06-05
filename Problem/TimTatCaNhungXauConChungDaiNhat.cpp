#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1 = " " + s1;
    s2 = " " + s2;
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
    vector<vector<set<string>>> lcs(n + 2, vector<set<string>>(m + 2));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if(dp[i][j] == 1) {
                    lcs[i][j].insert(string(1, s1[i]));
                } else {
                    for (string k : lcs[i - 1][j - 1]) {
                        lcs[i][j].insert(k + s1[i]);
                    }
                }

            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

                if (dp[i][j] == dp[i - 1][j]) {
                    for (string k : lcs[i - 1][j]) {
                        lcs[i][j].insert(k);
                    }
                }

                if (dp[i][j] == dp[i][j - 1]) {
                    for (string k : lcs[i][j - 1]) {
                        lcs[i][j].insert(k);
                    }
                }
            }
        }
    }

    if(dp[n][m] == 0) {
        cout << "khong co xau con chung";
        return 0;
    }

    for(string s : lcs[n][m]) {
        cout << s << "\n";
    }
   
    return 0;
}

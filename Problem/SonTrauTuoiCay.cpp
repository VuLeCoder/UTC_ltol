#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long solve(vector<pair<long, long>>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int left = arr[0].first, right = arr[0].second;
    int ans = right - left;
    for(int i=1; i<n; ++i) {
        if(arr[i].first >= right) {
            left = arr[i].first;
            right = arr[i].second;
            ans += right - left;
            continue;
        }

        if(arr[i].second <= right) {
            left = arr[i].first;
            continue;
        }

        ans += arr[i].second - right;
        right = arr[i].second;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<long, long>> arr(n);
        int x, r;
        for(int i=0; i<n; ++i) {
            cin >> x >> r;
            arr[i] = {x - r, x + r};
        }
        cout << solve(arr) << "\n";
    }

    return 0;
}

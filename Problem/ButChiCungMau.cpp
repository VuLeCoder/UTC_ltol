#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }

    int left = 0, right = 0, maxColor = 0;
    while(right + 1 < n) {
        if(a[right] != a[right + 1]) {
            maxColor = max(maxColor, right - left + 1);
            left = right + 1;
        }
        ++right;
    }
    maxColor = max(maxColor, right - left + 1);
    cout << n - maxColor;
    return 0;
}

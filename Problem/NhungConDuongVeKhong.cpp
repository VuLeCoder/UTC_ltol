#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<int> res;
    vector<bool> vi(n + 1, false);

    queue<int> q;
    q.push(n);
    vi[n] = true;


    while(!q.empty()) {
        int curr = q.front(); q.pop();
        res.push_back(curr);

        for(int i=1; i<=curr/2; ++i) {
            if(curr % i != 0 || i > curr / i) {
                continue;
            }

            int next = (i - 1) * (curr / i + 1);
            if(!vi[next]) {
                vi[next] = true;
                q.push(next);
            }
        }
    }

    sort(res.begin(), res.end());
    for(int num : res) {
        cout << num << " ";
    }

    return 0;
}

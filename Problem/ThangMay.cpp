#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k, m, s, f;
    cin >> n >> k >> m >> s >> f;

    bool visited[n + 1] = {false};
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int step = 0;
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; ++i) {
            int curr = q.front();
            q.pop();

            if(curr == f) {
                cout << step;
                return 0;
            }

            if(curr + k <= n && !visited[curr + k]) {
                q.push(curr + k);
                visited[curr + k] = true;
            }

            if(curr - m >= 1 && !visited[curr - m]) {
                q.push(curr - m);
                visited[curr - m] = true;
            }
        }
        step++;
    }
    cout << -1;

    return 0;
}

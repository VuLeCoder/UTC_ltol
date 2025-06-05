#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    int step = 0;
    queue<pair<int, int>> q;
    map<pair<int, int>, bool> visited;
    q.push({0, 0});

    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto [x, y] = q.front();
            q.pop();
            
            if(x == k || y == k) {
                cout << step << "\n";
                return 0;
            }

            pair<int, int> next[] = {{x, 0}, {0, y}, {n, y}, {x, m}, {max(0, x + y - m), min(m, x + y)}, {min(x + y, n), max(x + y - n, 0)}};
            for(const auto& p : next) {
                if(visited.find(p) == visited.end()) {
                    visited[p] = true;
                    q.push(p);
                }
            }
        }
        ++step;
    }
    cout<<"Khong dong duoc nuoc";
    return 0;
}

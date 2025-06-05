#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    deque<long long> dq;
    long long ans = 0;
    for(int i=0; i<n; ++i) {
        while(dq.size() >= k) {
            dq.pop_front();
        }
        
        long long tmp = 0;
        while(!dq.empty() && tmp < m) {
            if(tmp + dq.front() <= m) {
                tmp += dq.front();
                dq.pop_front();
            } else {
                long long y = dq.front();
                dq.pop_front();

                dq.push_front(y + tmp - m);
                tmp = m;
            }
        }

        int x; cin >> x;
        if(tmp + x <= m) {
            tmp += x;
        } else {
            long long y = x;
            x = m - tmp;
            tmp = m;

            dq.push_back(y - x);
        }
        ans += tmp;
    }

    while(!dq.empty() && dq.front() != 0) {
        while(dq.size() >= k) {
            dq.pop_front();
        }
        
        long long tmp = 0;
        while(!dq.empty() && tmp < m) {

            if(tmp + dq.front() <= m) {
                tmp += dq.front();
                dq.pop_front();
            } else {
                long long y = dq.front();
                dq.pop_front();

                dq.push_front(y + tmp - m);
                tmp = m;
            }
        }

        dq.push_back(0);
        ans += tmp;
    }
    cout << ans;

    return 0;
}

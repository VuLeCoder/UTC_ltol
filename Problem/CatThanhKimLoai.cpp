#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    set<int> s;
    multiset<int> ms;
    int n, m;
    cin >> n >> m;
    s.insert(0), s.insert(m);
    ms.insert(m);

    for(int i=0; i<n; ++i) {
        int x; cin >> x;
        auto it = s.lower_bound(x);
        auto pre = prev(it);
		
        ms.erase(ms.find(*it - *pre));
        ms.insert(x - *pre);
        ms.insert(*it - x);

        s.insert(x);

       cout << *ms.rbegin() << " ";
    }
    
    return 0;
}

#include <iostream>
#include <set>
#include <vector>
using namespace std;

string strr;
set<string> s;

void backtrack(const string& str, int i, int n, vector<bool>& a) {
    if (i == n) {
        s.insert(str);
        return;
    }

    for (int j = 1; j <= n; ++j) {
        if(a[j - 1]) {
            continue;
        }

        a[j - 1] = true;
        backtrack(str + strr[j - 1], i + 1, n, a);
        a[j - 1] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> strr;
    int n = strr.size();
    vector<bool> a(n);
    backtrack("", 0, n, a);

    for(string strrr : s) {
        cout << strrr << "\n";
    }

    return 0;
}

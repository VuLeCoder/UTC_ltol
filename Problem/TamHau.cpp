#include <iostream>
#include <vector>
using namespace std;

int n, total;
vector<bool> col, diag1, diag2;

void solve(int row) {
    if (row == n) {
        total++;
        return;
    }

    for (int c = 0; c < n; ++c) {
        if (row == c || row + c == n - 1) continue;

        if (!col[c] && !diag1[row - c + n - 1] && !diag2[row + c]) {
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;
            solve(row + 1);
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
        }
    }
}

int main() {
    cin >> n;

    total = 0;
    col.assign(n, false);
    diag1.assign(2 * n - 1, false);
    diag2.assign(2 * n - 1, false);

    solve(0);
    cout << total;

    return 0;
}

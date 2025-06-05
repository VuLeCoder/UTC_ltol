#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n, m; cin >> n >> m;
	cout << min(n, m);
	return 0;
}
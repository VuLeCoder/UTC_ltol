#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int t; cin >> t;
	cin.ignore();
	string name;
	while(t--) {
		getline(cin, name);
		
		string ans = ""; ans += name[0];
		for(int i=1; i<name.length(); ++i)
			if(name[i] == ' ')
				ans += name[i + 1];
		cout << ans << "\n";
	}
	return 0;
}
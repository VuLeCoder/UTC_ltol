#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

char cdfga[] = {'C', 'D', 'F', 'G', 'A'};
char nextx[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B'};

string findNext(string& x) {
	if(x.length() == 2) {
		for(int i=0; i<5; ++i) {
			if(x[0] == cdfga[i]) {
				string ans = "";
				ans += x[0];
				ans += '#';
				ans += x[1];
				return ans;
			}
		}
		
		string ans = "";
		for(int i=0; i<7; ++i) {
			if(x[0] == nextx[i]) {
				if(i < 6) {
					ans += nextx[i + 1];
					ans += x[1];
				} else {
					ans += 'C';
					ans += (x[1] + 1);
				}
			}
		}
		return ans;
	}
	
	string ans = "";
	for(int i=0; i<7; ++i) {
		if(x[0] == nextx[i]) {
			if(i < 6) {
				ans += nextx[i + 1];
				ans += x[2];
			} else {
				ans += 'C';
				ans += (x[2] + 1);
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	string x; cin >> x;
	int n; cin >> n;
	
	for(int i=0; i<n; ++i) {
		x = findNext(x);
	}
	cout << x;
	
	return 0;
}
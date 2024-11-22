#include <iostream>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	string str; cin >> str;
	int arr[26];
	for(int i=0; i<26; ++i) arr[i] = -1;
	for(char c : str) arr[c - 'a'] = c - 'a';
	
	int q; cin >> q;
	char query[q][3];
	for(int i=0; i<q; ++i)
	{
		char x; cin >> x;
		if(x == 'R')
		{
			query[i][0] = 'R';
			char a, b; cin >> a >> b;
			query[i][1] = a;
			query[i][2] = b;
		}
		else
		{
			query[i][0] = 'D';
			char a; cin >> a;
			query[i][1] = a;
		}
	}
	
	for(int i=q-1; i>=0; --i)
	{
		if(query[i][0] == 'R')
			arr[query[i][1] - 'a'] = arr[query[i][2] - 'a'];
		
		else 
			arr[query[i][1] - 'a'] = -1;
	}
	
	for(char c : str)
		if(arr[c - 'a'] != -1)
			cout << (char)(arr[c - 'a'] + 'a');
	return 0;
}

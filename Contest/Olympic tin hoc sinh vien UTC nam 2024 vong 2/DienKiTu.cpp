#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string s; cin>>s;
	int start = 0, ans = 1;
	while(s[start] == '*')
	{
		start++;	
	} 
	for(int i=start; i<s.length(); ++i)
		if(s[i] == '*')
			s[i] = s[i-1];
	
	char cur = s[start];
	for(int i=start+1; i<s.length(); ++i)
	{
		if(s[i] != cur) ans++, cur = s[i];
	}
	cout<<ans;

	return 0;
}
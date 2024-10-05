#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	long long n; cin>>n;
	string bit;
	while(n > 0)
	{
		int x = n%2;
		bit += (x == 1)? '1' : '0';
		n/=2;
		
	}
	while(bit.length() < 16) bit+='0';
	for(int i=bit.length()-1; i>=bit.length()-8; --i) cout<<bit[i];
	cout<<"\n";
	for(int i=7; i>=0; --i) cout<<bit[i];
    
	return 0;
}
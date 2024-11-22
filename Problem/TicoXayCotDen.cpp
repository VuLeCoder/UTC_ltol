#include <iostream>
using namespace std;

unsigned long long pow2(int n)
{
	return 1ULL << n;
}

long long function(unsigned long long n, int pow)
{
	unsigned long long low = pow2(pow);
	if(n < low) return 0;
	
	unsigned long long high = n/low;
	high *= low;
	return (high - low) / low + 1;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	unsigned long long l, r; cin >> l >> r;
	l--;
	
	long long a[64], dup = 0;
	for(int i=63; i>0; --i)
	{
		long long tmp = function(r, i) - function(l, i);
		a[i] = tmp - dup;
		dup = tmp;
	}
	
	long long res = 0;
	for(long long i=1; i<64; ++i) res += i * a[i];
	cout << res;
	return 0;
}

#include <iostream>
using namespace std;
long long solve(long long n) 
{
    long long ans = 0;
    for (int i = 0; (1LL << i) <= n; i++) 
    {
        long long fullCycles = (n+1) / (1LL << (i + 1));
        ans += fullCycles * (1LL << i);
        long long remainder = (n + 1) % (1LL << (i + 1));
        if (remainder > (1LL << i))
            ans += remainder - (1LL << i);
    }
    return ans;
}

int main() 
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

    long long n; cin>>n;
    cout << solve(n);

    return 0;
}

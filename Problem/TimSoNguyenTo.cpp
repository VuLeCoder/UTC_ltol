#include <iostream>
#include <cstring>
#define MAX 1000001
using namespace std;

bool prime[MAX];
void Sang_so_nguyen_to()
{
    memset(prime, true, sizeof(prime));
    for (int i = 2; i * i < MAX; ++i)
        if (prime[i])
            for (int j = i * i; j < MAX; j += i)
                prime[j] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Sang_so_nguyen_to();

    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        for (int i = a; i <= b; ++i)
            if (prime[i])
                cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
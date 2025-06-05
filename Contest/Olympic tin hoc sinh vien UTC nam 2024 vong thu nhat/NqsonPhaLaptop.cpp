#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned long long n, x, y1, y2, z;
    cin >> n >> x >> y1 >> y2 >> z;

    unsigned long long min = z;

    if (x * n < min)
        min = x * n;

    if ((y1 * n + y2) < min)
        min = y1 * n + y2;

    cout << min;

    return 0;
}
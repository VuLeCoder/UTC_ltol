#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    vector<bool> marked(n, false);

    for(int i=0; i<n; ++i)  
    {
        int x; cin >> x;
        arr[i] = {x, i};
    }
    sort(arr.begin(), arr.end());

    int ans = 0;
    for(auto &[value, index] : arr) 
    {
        if(marked[index]) continue;

        marked[index] = true;
        if(index + 1 < n)  marked[index + 1] = true;
        if(index - 1 >= 0) marked[index - 1] = true;
        ++ans;
    }
    cout << ans;
}

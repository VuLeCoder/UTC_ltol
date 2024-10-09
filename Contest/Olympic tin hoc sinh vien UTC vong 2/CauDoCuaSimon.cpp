#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

map<vector<string>, int> mp;

void set_status(vector<string> &coins, int x, int y)
{
    coins[x][y] = (coins[x][y] == '0') ? '1' : '0';
    if (x - 1 >= 0)
        coins[x - 1][y] = (coins[x - 1][y] == '0') ? '1' : '0';
    if (x + 1 < 4)
        coins[x + 1][y] = (coins[x + 1][y] == '0') ? '1' : '0';
    if (y - 1 >= 0)
        coins[x][y - 1] = (coins[x][y - 1] == '0') ? '1' : '0';
    if (y + 1 < 4)
        coins[x][y + 1] = (coins[x][y + 1] == '0') ? '1' : '0';
}

void set_up()
{
    vector<string> coins(4, "0000");
    queue<vector<string>> q;
    mp[coins] = 0;
    q.push(coins);

    while (!q.empty())
    {
        vector<string> curr = q.front();
        q.pop();
        int cnt = mp[curr];

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
            {
                vector<string> next = curr;
                set_status(next, i, j);
                if (mp.find(next) == mp.end())
                {
                    mp[next] = cnt + 1;
                    q.push(next);
                }
            }
    }
}

int main()
{
    set_up();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        // nhap
        vector<string> begin(4), end(4);
        for (int i = 0; i < 4; ++i)
            cin >> begin[i];
        for (int i = 0; i < 4; ++i)
            cin >> end[i];

        // giai
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                begin[i][j] = (begin[i][j] - '0') ^ (end[i][j] - '0') + '0';

        if (mp.find(begin) != mp.end())
            cout << mp[begin] << "\n";
        else
            cout << -1 << '\n';
    }

    return 0;
}
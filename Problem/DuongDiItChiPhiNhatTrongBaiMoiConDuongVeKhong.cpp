#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int bfs(int s, int f)
{
	if(s == f) return 0;
	
	unordered_map<int, int> check;
	queue<pair<int, int>> q;
	
	q.push({s, 0});
	while(!q.empty())
	{
		if(q.front().first == f) { q.pop(); continue; }
		int n = q.front().first;
		int cost = q.front().second;
		q.pop();
		
		for(int i=1; i<n; ++i)
		{
			if(n % i == 0 && n/i >= i)
			{
				int num = (i-1) * (n/i + 1);
				int tmp;
				if((n/i) % i == 0) tmp = (n/i)/i;
				else tmp = n/i + i;
				
				if(!check.count(num) || check[num] > tmp+cost ) 
					check[num] = tmp+cost, q.push({num, tmp+cost});
			}
			if(n % i == 0 && n/i < i) break;
		}
	}
	
	if(check.count(f)) return check[f];
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int t; cin>>t;
	while(t--)
	{
		int s, f; cin >> s >> f;
		cout << bfs(s, f) << "\n";
	}
	
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int check = 0;
	vector<string> arr(3);
	string s;
	while(cin>>s)
	{
		if(s == "END") break;
		arr[check] = s;
		check++;
		if(check == 3)
		{
			check = 0;
			vector<int> row[3];
			for(int i=0; i<s.length(); ++i)
			{
				if(arr[0][i] == '1') row[0].push_back(i);
				if(arr[1][i] == '1') row[1].push_back(i);
				if(arr[2][i] == '1') row[2].push_back(i);
			}
			
			bool IsValid = false;
			for(int i : row[0])
			{
				for(int j : row[1])
				{
					if(i != j)
						for(int k : row[2])
							if(i != k && j != k)
							{
								IsValid = true;
								break;
							}
					if(IsValid) break;
				}
				if(IsValid) break;
			}
			
			cout << (IsValid ? "YES\n" : "NO\n");
		}
	}
	return 0;
}

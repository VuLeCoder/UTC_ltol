#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n; cin >> n;
	int a[n];
	for(int i=0; i<n; ++i) cin>>a[i];
	
	int Min = 0, Max = 0, col = 0, sum = 0;
	for(int i=0; i<n; ++i)
	{
		col += abs(a[i]);
		sum += a[i];
		Max = max(Max, sum);
		Min = min(Min, sum);
	}
	
	int row;
	if(Min < 0 && Max > 0) row = Max - Min;
	else row = max(abs(Min), Max);
	
	int pos = row + Min - 1;
	if(a[0] < 0) pos++;

	
	char chart[row][col];
	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			chart[i][j] = '-';
	
	int vtR = pos, vtC = 0;
	for(int i=0; i<n; ++i)
	{
		if(i > 0 && a[i] * a[i-1] < 0)
		{
			if(a[i] > 0) vtR--;
			else vtR++;
		}
		
		for(int j=0; j<abs(a[i]); ++j)
		{
			if(a[i] > 0) chart[vtR][vtC] = '/', vtR--;
			if(a[i] < 0) chart[vtR][vtC] = '\\', vtR++;
			vtC++;
		}
	}
	
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
			cout << chart[i][j];
		cout << '\n';
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 9;
vector<vector<int>> Sudoku(N, vector<int>(N));

bool IsValid(int num, int x, int y)
{
	for(int i=0; i<N; ++i)
		if(Sudoku[x][i] == num || Sudoku[i][y] == num)
			return false;
	
	int dx = x - x%3, dy = y - y%3;
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			if(Sudoku[i+dx][j+dy] == num)
				return false;
	
	return true;
}

void Sudoku_ans()
{
	for(int i=0; i<N; ++i)
	{
		for(int j=0; j<N; ++j)
			cout<<Sudoku[i][j]<<' ';
		cout<<"\n";
	}
	exit(0);
}

void solve_Sudoku()
{
	bool empty_space = false;
	int r=0, c=0;
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			if(Sudoku[i][j] == 0)
			{
				empty_space = true;
				r = i, c = j;
				break;
			}
	
	if(!empty_space) Sudoku_ans();
	for(int num=1; num<=9; ++num)
	{
		if(IsValid(num, r, c))
		{
			Sudoku[r][c] = num;
			solve_Sudoku();
			Sudoku[r][c] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			cin>>Sudoku[i][j];
	
	solve_Sudoku();
	
	return 0;
}
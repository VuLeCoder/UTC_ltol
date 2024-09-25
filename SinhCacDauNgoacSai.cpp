#include <iostream>
#include <vector>
using namespace std;

int n;
char str[24];

void backtrack(char str[], int close, int open, int index, bool isvalid)
{
	if(index == 2*n) { printf("%s\n",str); return;}
	
	if(open > close) isvalid = false;
	
	if(open > 0)
		if(!(open == 1 && open <= close && isvalid))
		{
			str[index] = '(';
            backtrack(str, close, open-1, index+1, isvalid);
        }
	
	if(close > 0)
	{
		str[index] = ')';
		backtrack(str, close-1, open, index+1, isvalid);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin>>n;

	backtrack(str, n, n, 0, true);
	return 0;
}
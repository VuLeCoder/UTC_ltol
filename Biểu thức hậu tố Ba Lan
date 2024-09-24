#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

map<char, int> priority;
void set_priority(){
	priority['/'] = 2;
	priority['*'] = 2;
	priority['+'] = 1;
	priority['-'] = 1;
	priority['('] = 0;
}

int str_to_int(string s)
{
	int num = 0;
	for(int i=0; i<s.length(); ++i)
		num = num*10 + s[i]-'0';
	return num;
}

int calc(int num1, int num2, string x)
{
	switch(x[0])
	{
		case '+':
			return num1+num2;
		case '-':
			return num1-num2;
		case '*':
			return num1*num2;
		case '/':
			return num1/num2;
	}
}

int main()
{
	set_priority();
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	string exp; cin>>exp;
	
	stack<string> BLExp;
	stack<char> Opr;
	
	int n = exp.length();
	string num = "";
	for(int i=0; i<n; ++i)
	{
		if(exp[i] >='0' && exp[i] <='9')
			num += exp[i];
		else // exp[i] ko phải chữ số
		{
			if(num != "")
				BLExp.push(num),
				num = "";
			
		// exp[i] là dấu ( , )
			if(exp[i] == '(') Opr.push(exp[i]);
			else if(exp[i] == ')')
			{
				while(Opr.top() != '(')
				{
					string temp = "";
					temp += Opr.top();
					BLExp.push(temp);
					Opr.pop();
				}
				Opr.pop();
			}
			
		//exp[i] là toán tử	
			else
			{
				if(Opr.empty()) Opr.push(exp[i]);
				else
				{
					if(priority[Opr.top()] >= priority[exp[i]])
					{
						while(!Opr.empty() && priority[Opr.top()] >= priority[exp[i]])
						{
							string temp = "";
							temp += Opr.top();
							BLExp.push(temp);
							Opr.pop();
						}
						Opr.push(exp[i]);
					}
					else Opr.push(exp[i]);
				}
			}
		}
	}
	
// POP các toán tử còn lại trong Opr, PUSH vào BLExp
	if(num != "") BLExp.push(num);
	while(!Opr.empty())
	{
		string temp = "";
		temp += Opr.top();
		BLExp.push(temp);
		Opr.pop();
	}

// Đảo ngược các phần tử trong BLExp
	stack<string> tmp;
	while(!BLExp.empty())
	{
		string top = BLExp.top();
		tmp.push(top);
		BLExp.pop();
	}
	stack<string> BLexp(tmp);
	
// check
	while(!tmp.empty())
	{
		cout<<tmp.top();
		tmp.pop();
	}
	cout<<"\n";
	
	stack<int> T;
	while(!BLexp.empty())
	{
		string tmp = BLexp.top();
		BLexp.pop();
		if(tmp.length() > 1 || (tmp >= "0" && tmp <= "9"))
		{
			int num = str_to_int(tmp);
			T.push(num);
		}
		else
		{
			int num2 = T.top();
			T.pop();
			int num1 = T.top();
			T.pop();
			int num = calc(num1, num2, tmp);
			T.push(num);
		}
	}
	cout << T.top();
	
	return 0;
}

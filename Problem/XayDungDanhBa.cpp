#include <iostream>
using namespace std;

class Node
{
	private:
		int repeat;
		Node* arr['z'-'a'+1];
	
	public:
		Node()
		{
			repeat = 0;
			for(int i=0; i<='z'-'a'; ++i) arr[i] = nullptr;
		}
		
		void add(Node* root, string &str)
		{
			Node* tmp = root;
			int n = str.length();
			for(int i=0; i<n; ++i)
			{
				if(tmp->arr[str[i]-'a'] == nullptr)
					tmp->arr[str[i]-'a'] = new Node();
				
				tmp = tmp->arr[str[i]-'a'];
				tmp->repeat++;
			}
		}
		
		int find(Node* root, string &str)
		{
			Node* tmp = root;
			int n = str.length();
			for(int i=0; i<n; ++i)
			{
				if(tmp->arr[str[i]-'a'] == nullptr) return 0;
				tmp = tmp->arr[str[i]-'a'];
			}
			return tmp->repeat;
		}
	
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	Node* contacts = new Node();
	
	int n; cin >> n;
	string a,s;
	while(n--)
	{
		cin >> a >> s;
		if(a[0] == 'a')
			contacts->add(contacts, s);
		else
			cout << contacts->find(contacts, s) << "\n";	
	}
	return 0;
}

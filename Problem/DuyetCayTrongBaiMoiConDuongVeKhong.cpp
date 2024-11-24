#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int val;
	vector<Node*> child;
};

void Build(Node* root)
{
	int n = root->val;
	for(int i=1; i<n; ++i)
	{
		if(n % i == 0 && n/i >= i)
		{
			Node* tmp = new Node;
			tmp->val = (i-1) * (n/i + 1);
			Build(tmp);
			root->child.push_back(tmp);
		}
		if(n % i == 0 && n/i < i) break;
	}
}

void Preorder(Node* root)
{
	cout << root->val << " ";
	for(Node* x : root->child) Preorder(x);
}

void Inorder(Node* root)
{
	if(!root->child.empty()) Inorder(root->child[0]);
	cout << root->val << " ";
	
	int n = root->child.size();
	for(int i=1; i<n; ++i)
		Inorder(root->child[i]);
}

void Postorder(Node *root)
{
	for(Node* x : root->child) Postorder(x);	
	cout << root->val << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n; cin>>n;
	Node* root = new Node;
	root->val = n;
	
	Build(root);
	
	Preorder(root); cout << "\n";
	Inorder(root); cout << "\n";
	Postorder(root);
	
	return 0;
}

// PostOrder Traversal - Iteratively
#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

// structure of a node
struct Node{
	int data ;
	Node* left ; 
	Node* right ;

	Node(int x)
	{
		data = x ; 
		left = NULL ; 
		right = NULL ; 
	}
};

// PostOrder function
void PostOrder(Node* root)
{
	cout << "PostOrder : ";

	stack<Node*> s1; 
	stack<Node*> s2;

	s1.push(root);

	while(s1.empty() == false)
	{
		Node* curr = s1.top();
		s1.pop();

		s2.push(curr);

		if(curr->left != NULL)
		{
			s1.push(curr->left);
		}

		if(curr->right != NULL)
		{
			s1.push(curr->right);
		}
	} 

	while(s2.empty() == false)
	{
		Node* curr = s2.top();
		s2.pop();

		cout << curr->data << " ";
	}

	cout << endl;
}

int main()
{
	Node* root = new Node(10);
	Node* l1 = new Node(20);
	Node* l2 = new Node(30);
	Node* r1 = new Node(40);
	Node* r2 = new Node(50);

	root->left = l1;
	root->right = r1;
	l1->left = l2;
	l1->right = r2; 

	PostOrder(root);
	cout << endl;

	return 0;
}
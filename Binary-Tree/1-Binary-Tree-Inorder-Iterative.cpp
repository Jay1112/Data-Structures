// InOrder Traversal - Iteratively
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

// Inorder function
void InOrder(Node* root)
{
	Node* curr = root ; 
	stack<Node*> s;

	while(curr != NULL || s.empty()==false)
	{
		while(curr != NULL)
		{
			s.push(curr);
			curr = curr->left;
		}

		curr = s.top();
		s.pop();

		cout << curr->data << " ";
		curr = curr->right ; 
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

	cout << "Inorder : ";
	InOrder(root);

	return 0;
}
// PreOrder Traversal
#include <iostream>
#include <cstdlib>

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

// PreOrder function
void PreOrder(Node* root)
{
	if(root != NULL)
	{
		cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
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

	PreOrder(root);
	cout << endl;

	return 0;
}
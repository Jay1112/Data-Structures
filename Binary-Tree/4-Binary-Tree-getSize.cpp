// Get the size of the Binary Tree
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

// size of the Binary Tree
int getSize(Node* root)
{
	if(root == NULL)
	{
		return 0;
	}

	return 1 + getSize(root->left) + getSize(root->right);
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

	int size = getSize(root);

	cout << "Size : " << size << endl;

	return 0;
}
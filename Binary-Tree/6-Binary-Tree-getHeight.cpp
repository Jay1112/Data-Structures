// Get the Height of Binary Tree
#include <iostream>
#include <cstdlib>
#include <climits>
#include <algorithm>

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

// height of a binary tree 
int getHeight(Node* root)
{
	if(root == NULL)
	{
		return 0;
	}

	return 1 + max(getHeight(root->left),getHeight(root->right));
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

	int height = getHeight(root);

	cout << "Height : " << height << endl;

	return 0;
}
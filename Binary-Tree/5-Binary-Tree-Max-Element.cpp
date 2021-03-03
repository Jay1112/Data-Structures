// Get the Maximum element in Binary Tree
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

// MAX element 
int getMax(Node* root)
{
	if(root == NULL)
	{
		return INT_MIN;
	}

	return max(root->data,max(getMax(root->left),getMax(root->right)));

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

	int maxi = getMax(root);

	if(maxi == INT_MIN)
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << "Maximum : " << maxi << endl;
	}

	return 0;
}
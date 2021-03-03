// Binary Search Tree (Search Operation)
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

// search operation - Recursively
bool Search(Node* root,int data)
{
	if(root == NULL){
		return false;
	}else if(root->data == data){
		return true;
	}else if(root->data < data){
		return Search(root->right,data);
	}

	return Search(root->left,data);

}

int main()
{
	Node* root = new Node(30);
	Node* n1 = new Node(20);
	Node* n2 = new Node(10);
	Node* n3 = new Node(25);
	Node* n4 = new Node(50);

	root->left = n1;
	root->right = n4;
	n1->left = n2;
	n1->right = n3;

	int x = 50 ; 

	bool ch = Search(root,x);

	if(ch){
		cout << "Found" << endl;
	}else{
		cout << "Not Found" << endl;
	}

	return 0;
}
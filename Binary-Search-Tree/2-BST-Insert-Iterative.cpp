// Binary Search Tree (Insert Operation)
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

// inorder traversal
void Display(Node*  root)
{
	if(root != NULL){
		Display(root->left);
		cout << root->data << " ";
		Display(root->right);
	}
}

// search operation - Iteratively
Node* Insert(Node* root,int data)
{
	Node* temp = new Node(data);
	Node* parent = NULL;
	Node* child = root; 

	while(child != NULL)
	{
		parent = child ; 

		if(child->data == data){
			return root;
		}else if(child->data < data){
			child = child->right;
		}else{
			child = child->left;
		}
	}

	if(parent == NULL){
		return temp;
	}

	if(parent->data < data){
		parent->right = temp;
	}else{
		parent->left = temp;
	}

	return root;

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

	int x = 46 ; 

	Display(root); cout << endl;
	root = Insert(root,x);
	Display(root); cout << endl;

	return 0;
}

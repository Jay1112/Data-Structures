// Binary Search Tree (Delete Operation)
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

// getSuccessor funciton
Node* getSuccessor(Node* root)
{
	Node* temp = root->right;

	while(temp!= NULL && temp->left != NULL)
	{
		temp = temp->left;
	}

	return temp;

}

// Delete operation - Iteratively
Node* Delete(Node* root,int data)
{
	if(root == NULL){
		return root;
	}else if(root->data < data){
		root->right =  Delete(root->right,data);
	}else if(root->data > data){
		root->left = Delete(root->left,data);
	}else{

		// when a node has only right child
		if(root->left == NULL){
			Node* temp = root->right;
			free(root);
			return temp ;
		}else if(root->right == NULL){
			// when a node has only left child
			Node* temp = root->left;
			free(root);
			return temp;
		}else{
			// when a node has 2 children
			Node* succ = getSuccessor(root);
			root->data = succ->data;
			root->right = Delete(root->right,succ->data);
		}
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
	Node* n5 = new Node(5);

	root->left = n1;
	root->right = n4;
	n1->left = n2;
	n1->right = n3;
	n2->left = n5;

	int x = 20 ; 

	Display(root); cout << endl;
	root = Delete(root,x);
	Display(root); cout << endl;

	return 0;
}

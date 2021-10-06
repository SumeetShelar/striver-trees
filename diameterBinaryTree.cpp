#include <iostream>
using namespace std;
#include <algorithm>
#include "tree.h"
//-----------------------
int diameter = 0;

int height(Node* node) {
	if(node == NULL) return 0;
	int lh = height(node->left);
	int rh = height(node->right);
	
	diameter = max(diameter, lh+rh);
	
	return 1 + max(lh,rh);
}

int diameterBinaryTree(Node* root) {
	height(root);
	return diameter;
}
//------------------------------
int maxi = INT_MIN;

int maxPathDown(Node* node) {
	if(node == NULL) return 0;
	int leftsum = max(0, maxPathDown(node->left));
	int rightsum = max(0, maxPathDown(node->right));
	
	maxi = max(maxi, leftsum+rightsum+node->data);
	
	return node->data + max(leftsum,rightsum);
}

int maxPathSum(Node* root) {
	maxPathDown(root);
	return maxi;
}
//------------------------------------

bool isSameTree(Node* p, Node* q) {
	if(p==NULL || q==NULL) return (p==q);
	
	return (p->data == q->data)
		&& isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}

//-------------------------------------
int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->left = new Node(6);
	root->left->right->right = new Node(7);
	
	root->right->right = new Node(8);
	root->right->right->left = new Node(9);
	root->right->right->right = new Node(10);
	root->right->right->right->right = new Node(11);
	
	//-------Tree 2-----------
	Node* root2 = new Node(1);
	root2->left = new Node(2);
	root2->right = new Node(3);
	root2->left->left = new Node(4);
	root2->left->right = new Node(5);
	root2->left->right->left = new Node(6);
	root2->left->right->right = new Node(7);
	
	root2->right->right = new Node(8);
	root2->right->right->left = new Node(9);
	root2->right->right->right = new Node(10);
	root2->right->right->right->right = new Node(1);
	
//	cout << diameterBinaryTree(root);
//	cout << height(root);
//	cout << maxPathSum(root);
	cout << boolalpha << isSameTree(root, root2);
	
	return 0;
}




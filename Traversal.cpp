#include <iostream>
using namespace std;
#include "tree.h"
#include <vector>
#include <queue>
#include <stack>
#include <utility> // for Pair DS
#include <map>
#include <set>

//#include "preorderTraversal.h"
//#include "inorderTraversal.h"
//#include "postorderTraversal.h"
//#include "levelorderTraversal.h"
//#include "inorderTraversalIterative.h"
//#include "preorderTraversalIterative.h"
//#include "postorderTraversalIterative.h"
//#include "postorderTraversalIterative1Stack.h"
//#include "pre_in_post.h"
//#include "zigzagTraversal.h"
//#include "boundaryTraversal.h"
//#include "verticalTraversal.h"
//#include "topViewBinaryTree.h"
//#include "bottomViewBinaryTree.h"
//#include "leftSideViewBT.h"
//#include "rightSideViewBT.h"
//#include "checkSymmetricBT.h"
//#include "pathToNodeBT.h"
#include "lowestCommonAncestorBT.h"

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
//	root->right->right->right->left = new Node(11);
	
	vector<int> ans;
	vector<int> ans1;
	vector<vector<int>> dbl_ans;
	
//	preorderTraversal(root);
//	inorderTraversal(root);
//	postorderTraversal(root);
//	dbl_ans = levelorderTraversal(root);
//	for(auto i:dbl_ans) {
//		for(auto x:i)
//			cout << x << " ";
//		cout << endl;
//	}

//	ans = preorderTraversalIterative(root);
//	ans = inorderTraversalIterative(root);
//	ans = postorderTraversalIterative(root);
//	ans = postorderTraversalIterative1Stack(root);
//	pre_in_post(root);
//	ans = boundaryTraversal(root);
//	printBoundary(root);
//	dbl_ans = verticalTraversal(root);
//	ans = topViewBinaryTree(root);
//	ans = bottomViewBinaryTree(root);
//	ans = leftSideViewBT(root);
//	ans = rightSideViewBT(root);
//	cout << boolalpha << checkSymmetricBT(root);
//	ans = pathToNode(root, 6);
//	cout << lowestCommonAncestorBT(root, 10, 7);
	
//	for(auto i:ans) cout << i << " ";
//	cout << endl;
	
//	for(auto i:ans1) cout << i << " ";
//	cout << endl;
	
	return 0;
}

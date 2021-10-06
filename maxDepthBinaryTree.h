#include <algorithm>
int maxDepthBinaryTree(Node* root) {
	if(root == NULL) return 0;
	int lh = maxDepthBinaryTree(root->left);
	int rh = maxDepthBinaryTree(root->right);
	return 1 + max(lh,rh);
}


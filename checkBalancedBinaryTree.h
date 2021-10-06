int depth(Node* root) {
	if(root == NULL) return 0;
	
	int lh = maxDepthBinaryTree(root->left);
	if(lh == -1) return -1;
	int rh = maxDepthBinaryTree(root->right);
	if(rh == -1) return -1;
	
	if(abs(lh - rh) > 1) return -1;
	
	return 1 + max(lh,rh);
}

bool checkBalancedBinaryTree(Node* root) {
	if(depth(root) == -1) return false;
	return true;
}



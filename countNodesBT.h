int findLeftHeight(Node* node) {
	int h = 0;
	while(node) {
		h++;
		node = node->left;
	}
	return h;
}

int findRightHeight(Node* node) {
	int h = 0;
	while(node) {
		h++;
		node = node->right;
	}
	return h;
}

int countNodesBT(Node* root) {
	if(!root) return 0;
	
	int lh = findLeftHeight(root);
	int rh = findRightHeight(root);
	
	if(lh == rh) return (1<<lh) - 1;
	
	return 1 + countNodesBT(root->left) + countNodesBT(root->right);
}

Node* lastRightChild(Node* node) {
	if(node->right == NULL) return node;
	return lastRightChild(node->right);
}

Node* helper(Node* node) {
	if(node->left == NULL) return node->right;
	if(node->right == NULL) return node->left;
	
	Node* rightMostNode = lastRightChild(node->left);
	rightMostNode->right = node->right;
	return node->left;
}

Node* deleteNodeInBST(Node* root, int val) {
	if(!root) return NULL;
	if(root->data == val) return helper(root);
	
	Node* curr = root;
	while(curr) {
		if(curr->data > val) {
			if(curr->left!=NULL && curr->left->data == val) {
				curr->left = helper(curr->left);
				break;
			}
			curr = curr->left;
		} else {
			if(curr->right!=NULL && curr->right->data == val) {
				curr->right = helper(curr->right);
				break;
			}
			curr = curr->right;
		}
	}
	return root;
}

bool checkSymmetricHelper(Node* left, Node* right) {
	if(left==NULL || right==NULL) return left==right;
	
	if(left->data != right->data) return false;
	return checkSymmetricHelper(left->left, right->right)
			&&
			checkSymmetricHelper(left->right, right->left);
}

bool checkSymmetricBT(Node* root) {
	return (root==NULL) || checkSymmetricHelper(root->left, root->right);
}

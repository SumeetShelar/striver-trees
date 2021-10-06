void childSumPropertyBT(Node* root) {
	if(!root) return;
	
	if(root->left != NULL && root->right !=NULL) {
		if((root->left->data + root->right->data) < root->data) {
			if(root->left) root->left->data = root->data;
			if(root->right) root->right->data = root->data;
		}	
	}
	
	if(root->left) childSumPropertyBT(root->left);
	if(root->right) childSumPropertyBT(root->right);
	if(root->left && root->right) root->data = root->left->data + root->right->data;
	else if(root->left) root->data = root->left->data;
	else if(root->right) root->data = root->right->data;
}

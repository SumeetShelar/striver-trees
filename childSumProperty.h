void childSumPropertyBT(Node* root) {
	if(!root) return;
	
	int child = 0;
	if(root->left) child+= root->left->data;
	if(root->right) child+= root->right->data;
	
	if(child >= root->data) root->data = child;
	else {
		if(root->left) root->left->data = root->data;
		else if(root->right) root->right->data = root->data;
	}
	
	childSumPropertyBT(root->left);
	childSumPropertyBT(root->right);
	
	int tot=0;
	if(root->left) tot+= root->left->data;
	if(root->right) tot+= root->right->data;
	if(root->left || root->right) root->data = tot;
}

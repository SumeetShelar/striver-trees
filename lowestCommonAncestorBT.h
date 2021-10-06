int lowestCommonAncestorBT(Node* root, int x, int y) {
	if(!root) return -1;
	if(root->data == x || root->data == y) return root->data;
	
	int l = lowestCommonAncestorBT(root->left, x, y);
	int r = lowestCommonAncestorBT(root->right, x, y);
	
	if(l == -1) return r;
	else if(r == -1) return l;
	else return root->data;
}

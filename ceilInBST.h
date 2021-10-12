// ceil is bigger and the closest value to key
// for eg. for key 9, ceil will be 9 or greater than 9 like 10, 11

int ceilInBST(Node* root, int key) {
	int ceil = -1;
	while(root) {
		if(root->data == key) {
			ceil = root->data;
			return ceil;
		}
		
		if(root->data > key) {
			ceil = root->data;
			root = root->left;
		} else {
			root = root->right;
		}
	}
	return ceil;
}

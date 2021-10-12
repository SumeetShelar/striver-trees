Node* insertNodeInBST(Node* root, int val) {
	Node* node = new Node(val);
	if(!root) root = node;
	Node* curr = root;
	while(curr) {
		if(curr->data < val) {
			if(curr->right == NULL) {
				curr->right = node;
				break;
			}
			curr = curr->right;
		} else {
			if(curr->left == NULL) {
				curr->left = node;
				break;
			}
			curr = curr->left;
		}
	}
	return root;
}

Node* searchNodeInBST(Node* root, int x) {
	Node* curr = root;
	while(curr!=NULL && curr->data!=x) {
		curr = x < curr->data ? curr->left : curr->right;
	}
	return curr;
}

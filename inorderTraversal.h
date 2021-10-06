void inorderTraversal(Node* node) {
	if(node == NULL)
		return;
	inorderTraversal(node->left);
	cout << node->data << " ";
	inorderTraversal(node->right);
}

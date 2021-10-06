void postorderTraversal(Node* node) {
	if(node == NULL)
		return;
	postorderTraversal(node->left);
	postorderTraversal(node->right);
	cout << node->data << " ";
}

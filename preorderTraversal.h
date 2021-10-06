void preorderTraversal(Node* node) {
	if(node == NULL)
		return;
	cout << node->data << " ";
	preorderTraversal(node->left);
	preorderTraversal(node->right);
}

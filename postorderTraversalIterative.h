vector<int> postorderTraversalIterative(Node* root) {
	vector<int> ans;
	stack<Node*> s1;
	stack<Node*> s2;
	s1.push(root);
	while(!s1.empty()) {
		Node* node = s1.top();
		s2.push(node);
		s1.pop();
		if(node->left != NULL) s1.push(node->left);
		if(node->right != NULL) s1.push(node->right);
	}
	while(!s2.empty()) {
		ans.push_back(s2.top()->data);
		s2.pop();
	}
	return ans;
}


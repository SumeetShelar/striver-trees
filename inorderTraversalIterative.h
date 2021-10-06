vector<int> inorderTraversalIterative(Node* root) {
	vector<int> ans;
	stack<Node*> s;
	Node* node = root;
	while(true) {
		if(node!= NULL) {
			s.push(node);
			node = node->left;
		} else {
			if(s.empty()) break;
			node = s.top();
			s.pop();
			ans.push_back(node->data);
			node = node->right;
		}
	}
	return ans;
}

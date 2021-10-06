vector<int> preorderTraversalIterative(Node* root) {
	vector<int> ans;
	stack<Node*> s;
	s.push(root);
	
	while(!s.empty()) {
		Node* top = s.top();
		ans.push_back(top->data);
		s.pop();
		if(top->right!= NULL) s.push(top->right);
		if(top->left!=NULL) s.push(top->left);	
	}
	return ans;
}


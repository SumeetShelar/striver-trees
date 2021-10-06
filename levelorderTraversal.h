vector<vector<int>> levelorderTraversal(Node* root) {
	vector<vector<int>> ans;
	if(root == NULL) return ans;	
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		int size = q.size();
		vector<int> level(size);
		for(int i=0;i<size;i++) {
			Node* node = q.front();
			q.pop();
			level[i] = node->data;
			if(node->left != NULL) q.push(node->left);
			if(node->right != NULL) q.push(node->right);
		}
		ans.push_back(level);
	}
	return ans;
}

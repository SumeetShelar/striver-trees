vector<vector<int>> zigzagTraversal(Node* root) {
	vector<vector<int>> ans;
	if(root == NULL) return ans;
	queue<Node*> q;
	q.push(root);
	bool left_right = true;
	while(!q.empty()) {
		int size = q.size();
		vector<int> level(size);
		for(int i=0;i<size;i++) {
			Node* node = q.front();
			q.pop();
			
			int index = left_right ? i : (size-1 - i);
			
			level[index] = node->data;
			
			if(node->left != NULL) q.push(node->left);
			if(node->right != NULL) q.push(node->right);
		}
		left_right = !left_right;
		ans.push_back(level);
	}
	return ans;
}

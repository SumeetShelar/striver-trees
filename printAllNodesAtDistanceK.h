void markParents(Node* root, map<Node*, Node*> &parentTrack) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* node = q.front();
		q.pop();
		if(node->left) {
			parentTrack[node->left] = node;
			q.push(node->left);
		}
		if(node->right) {
			parentTrack[node->right] = node;
			q.push(node->right);
		}
	}
}

vector<int> printAllNodesAtDistanceK(Node* root, Node* targetNode, int k) {
	map<Node*, Node*> parentTrack;
	markParents(root, parentTrack);
	
	map<Node*, bool> visited;
	queue<Node*> q;
	q.push(targetNode);
	visited[targetNode] = true;
	int curr_lvl = 0;
	
	while(!q.empty()) {
		int size = q.size();
		if(curr_lvl == k) break;
		curr_lvl++;
		for(int i=0;i<size; i++) {
			Node* node = q.front();
			q.pop();
			if(node->left && !visited[node->left]) {
				q.push(node->left);
				visited[node->left] = true;
			}
			if(node->right && !visited[node->right]) {
				q.push(node->right);
				visited[node->right] = true;
			}
			if(parentTrack[node] && !visited[parentTrack[node]]) {
				q.push(parentTrack[node]);
				visited[parentTrack[node]] = true;
			}
		}
	}
	vector<int> ans;
	while(!q.empty()) {
		Node* tmp = q.front(); q.pop();
		ans.push_back(tmp->data);
	}
	return ans;
}

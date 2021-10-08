Node* markParent(Node* root, map<Node*, Node*> &trackParent, int start) {
	queue<Node*> q;
	q.push(root);
	Node* target;
	while(!q.empty()) {
		
		Node* node = q.front();
		q.pop();
		if(node->data == start) target = node;
		if(node->left) {
			trackParent[node->left] = node;
			q.push(node->left);
		}
		if(node->right) {
			trackParent[node->right] = node;
			q.push(node->right);
		}
	}
	return target;
}

int minTimeToBurnBT(Node* root, int start) {
	map<Node*, Node*> trackParent;
	Node* target = markParent(root, trackParent, start);
	
	map<Node*, bool> visited;
	queue<Node*> q;
	q.push(target);
	visited[target] = true;
	int num = 0;
	while(!q.empty()) {
		int size = q.size();
		bool flag = false;
		for(int i=0;i<size;i++) {
			Node* node = q.front();
			q.pop();
			if(node->left && !visited[node->left]) {
				q.push(node->left);
				visited[node->left] = true;
				flag = true;
			}
			if(node->right && !visited[node->right]) {
				q.push(node->right);
				visited[node->right] = true;
				flag = true;
			}
			if(trackParent[node] && !visited[trackParent[node]]) {
				q.push(trackParent[node]);
				visited[trackParent[node]] = true;
				flag = true;
			}
		}
		if(flag) num++;
	}
	return num;
}

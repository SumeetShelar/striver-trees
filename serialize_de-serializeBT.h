string serialize(Node* root) {
	if(!root) return "";
	
	string s="";
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* node = q.front();
		q.pop();
		if(node == NULL) s.append("#,");
		else s.append(to_string(node->data) + ",");
		
		if(node!=NULL) {
			q.push(node->left);
			q.push(node->right);
		}
	}
	return s;
}

Node* deSerialize(string data) {
	if(data.size() == 0) return NULL;
	stringstream s(data);
	string str;
	getline(s, str, ',');
	Node* root = new Node(stoi(str));
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* node = q.front();
		q.pop();
		getline(s, str, ',');
		if(str == "#") node->left = NULL;	
		else {
			Node* leftNode = new Node(stoi(str));
			node->left = leftNode;
			q.push(leftNode);
		}
		
		getline(s, str, ',');
		if(str == "#") node->right = NULL;
		else {
			Node* rightNode = new Node(stoi(str));
			node->right = rightNode;
			q.push(rightNode);
		}
	}
	return root;
}

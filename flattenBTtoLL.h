void flattenBTtoLLMorris(Node* root) {
	Node* curr = root;
	while(curr) {
		if(curr->left) {
			Node* prev = curr->left;
			while(prev->right) {
				prev = prev->right;
			}
			prev->right = curr->right;
			curr->right = curr->left;
			curr->left = NULL;
		}
		curr = curr->right;
	}
}

Node* r_prev = NULL;

void flattenBTtoLLRecursive(Node* root) {
	if(!root) return;
	
	flattenBTtoLLRecursive(root->right);
	flattenBTtoLLRecursive(root->left);
	
	root->right = r_prev;
	root->left = NULL;
	r_prev = root;
}

void flattenBTtoLLIterative(Node* root) {
	if(!root) return;
	stack<Node*> st;
	st.push(root);
	while(!st.empty()) {
		Node* curr = st.top();
		st.pop();
		if(curr->right) {
			st.push(curr->right);
		}
		if(curr->left) {
			st.push(curr->left);
		}
		if(!st.empty()) {
			curr->right = st.top();
		}
		curr->left = NULL;
	}
}

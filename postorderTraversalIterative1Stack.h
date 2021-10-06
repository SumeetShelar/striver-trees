vector<int> postorderTraversalIterative1Stack(Node* root) {
	stack<Node*> st;
	vector<int> ans;
	Node* curr = root;
	Node* temp = NULL;
	while(!st.empty() || curr!=NULL) {
		if(curr!=NULL) {
			st.push(curr);
			curr = curr->left;
		} else {
			temp = st.top()->right;
			if(temp==NULL) {
				temp = st.top();
				st.pop();
				ans.push_back(temp->data);
				while(!st.empty() && temp==st.top()->right) {
					temp = st.top();
					st.pop();
					ans.push_back(temp->data);
				}
			} else {
				curr = temp;
			}
		}
	}
	return ans;
}

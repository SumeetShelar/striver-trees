bool getPath(Node* node, vector<int> &ans, int x) {
	if(!node) return false;
	ans.push_back(node->data);
	if(node->data == x) return true;
	
	if(getPath(node->left, ans, x) || getPath(node->right, ans, x)) return true;
	ans.pop_back();
	return false;
}

vector<int> pathToNode(Node* root, int x) {
	vector<int> ans;
	if(!root) return ans;
	
	bool flag = getPath(root, ans, x);
	if(flag) return ans;
	else {
		ans.clear();
		ans.push_back(-1);
		return ans;	
	}
}

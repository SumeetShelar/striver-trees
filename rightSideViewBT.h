void recursionStepRight(Node* node, vector<int> &ans, int lvl=0) {
	if(!node) return;
	
	if(lvl == ans.size()) ans.push_back(node->data);
	
	if(node->right) recursionStepRight(node->right, ans, lvl+1);
	if(node->left) recursionStepRight(node->left, ans, lvl+1);
}

vector<int> rightSideViewBT(Node* root) {
	vector<int> ans;
	recursionStepRight(root, ans);
	return ans;
}

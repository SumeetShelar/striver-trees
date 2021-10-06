void recursionStepLeft(Node* node, vector<int> &ans, int lvl=0) {
	if(!node) return;
	
	if(lvl == ans.size()) ans.push_back(node->data);
	
	if(node->left) recursionStepLeft(node->left, ans, lvl+1);
	if(node->right) recursionStepLeft(node->right, ans, lvl+1);
}

vector<int> leftSideViewBT(Node* root) {
	vector<int> ans;
	recursionStepLeft(root, ans);
	return ans;
}

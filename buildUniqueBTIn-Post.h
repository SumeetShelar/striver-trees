Node* buildTreeHelper(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &inMap) {
	if(inStart > inEnd || postStart > postEnd) return NULL;
	
	Node* root = new Node(postorder[postEnd]);
	
	int inRoot = inMap[root->data];
	int numsLeft = inRoot - inStart;
	
	root->left = buildTreeHelper(inorder, inStart, inRoot-1, postorder, postStart, postStart+numsLeft-1, inMap);
	root->right = buildTreeHelper(inorder, inRoot+1, inEnd, postorder, postStart+numsLeft, postEnd-1, inMap);
	
	return root;
}

Node* buildTree(vector<int> &inorder, vector<int> &postorder) {
	map<int, int> inMap;
	for(int i=0;i<inorder.size();i++) {
		inMap[inorder[i]] = i;
	}
	Node* root = buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
	return root;
}


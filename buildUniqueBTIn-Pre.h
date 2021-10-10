Node* buildTreeHelper(vector<int> &inorder, int inStart, int inEnd, vector<int> &preorder, int preStart, int preEnd, map<int, int> &inMap) {
	if(inStart > inEnd || preStart > preEnd) return NULL;
	
	Node* root = new Node(preorder[preStart]);
	
	int inRoot = inMap[root->data];
	int numsLeft = inRoot - inStart;
	
	root->left = buildTreeHelper(inorder, inStart, inRoot - 1, preorder, preStart + 1, preStart + numsLeft, inMap);
	root->right = buildTreeHelper(inorder, inRoot + 1, inEnd, preorder, preStart + numsLeft + 1, preEnd, inMap);
	
	return root;
}

Node* buildTree(vector<int> &preorder, vector<int> &inorder) {
	map<int, int> inMap;
	for(int i=0;i<inorder.size();i++) {
		inMap[inorder[i]] = i;
	}
	Node* root = buildTreeHelper(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, inMap);
	return root;
}

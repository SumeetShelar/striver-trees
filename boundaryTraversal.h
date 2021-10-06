bool isLeaf(Node* node) {
	if(!node->left && !node->right) return true;
	return false;
}

void addLeftBoundary(Node* node, vector<int> &ans) {
	Node* curr = node->left;
	while(curr) {
		if(!isLeaf(curr)) ans.push_back(curr->data);
		if(curr->left) curr = curr->left;
		else curr = curr->right;
	}
}

void addLeaves(Node* node, vector<int> &ans) {
	if(isLeaf(node)) {
		ans.push_back(node->data);
		return;
	}
	if(node->left) addLeaves(node->left, ans);
	if(node->right) addLeaves(node->right, ans);
}

void addRightBoundary(Node* node, vector<int> &ans) {
	Node* curr = node->right;
//	vector<int> tmp;
	stack<int> st;
	while(curr) {
//		if(!isLeaf(curr)) tmp.push_back(curr->data);
		if(!isLeaf(curr)) st.push(curr->data);
		if(curr->right) curr = curr->right;
		else curr = curr->left;
	}
//-------Using vector------//
//	for(int i=tmp.size()-1;i>=0;--i) {
//		ans.push_back(tmp[i]);
//	}

//------Using Stack-------//
	while(!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
}

vector<int> boundaryTraversal(Node* root) {
	vector<int> ans;
	if(!root) return ans;
	if(!isLeaf(root)) ans.push_back(root->data);	
	
	addLeftBoundary(root, ans);
	addLeaves(root, ans);
	addRightBoundary(root, ans);
	
	return ans;
}

//----GFG Approach using recursion------//

void printLeft(Node* node) {
	if(!node) return;
	if(node->left) {
		cout << node->data << " ";
		printLeft(node->left);
	} else if(node->right) {
		cout << node->data << " ";
		printLeft(node->right);
	}
}

void printRight(Node* node) {
	if(node == NULL) return;
	if(node->right) {
		printRight(node->right);
		cout << node->data << " ";
	} else if(node->left) {
		printRight(node->left);
		cout << node->data << " ";
	}
}

void printLeaf(Node* node) {
	if(!node) return;
	printLeaf(node->left);
	
	if(isLeaf(node)) cout << node->data << " ";
	
	printLeaf(node->right);
}

void printBoundary(Node* node) {
	if(!node) return;
	cout << node->data << " ";
	printLeft(node->left);
	
	printLeaf(node->left);
	printLeaf(node->right);
	
	printRight(node->right);
}

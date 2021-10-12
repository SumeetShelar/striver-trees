// floor is smaller and the closest value to key
// for eg. for key 9, floor will be 9 or less than 9 like 8, 7

int floorInBST(Node* root, int key) {
	int floor;
	while(root) {
		if(root->data == key) return root->data;
		
		if(root->data < key) {
			floor = root->data;
			root = root->right;
		} else {
			root = root->left;
		}
	}
	return floor;
}

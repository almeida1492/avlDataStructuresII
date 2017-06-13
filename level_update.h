//This recursive function goes through the tree 
//and updates the node level attribute one buy one
//using the value in counter 

void level_update(AVL_NODE *root, int counter){
	counter++;
	root->level = counter;
	if(root->left){
		level_update(root->left, counter);
	}

	if(root->right){
		level_update(root->right, counter);
	}
}

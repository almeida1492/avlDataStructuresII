#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "P8AVLADT.h"

void print(AVL_NODE *root){
	
	if(root->right){
		print(root->right);
	}
	printf("(%i) %i %i\n", root->level, *(int*)root->dataPtr, root->bal);
	if(root->left){
		print(root->left);
	}
}

int compareInt (void* num1, void* num2){
//	Local Definitions 
	int key1;
	int key2;

//	Statements 
	key1 = *(int*)num1;
	key2 = *(int*)num2;
	if (key1 < key2)
	    return -1;
	if (key1 == key2)
	    return 0;
	return +1;
}	// compareInt 

int main(){
//	Declarations
	AVL_TREE *tree;
	int array[] = {70, 60, 80, 50, 75, 65, 45};
	int *container;

//	Statements
	tree = AVL_Create(compareInt);
	for (int i = 0; i < 7; ++i){
		container = (int*) malloc(sizeof(int));
		*container = array[i];

		AVL_Insert(tree, container);
	}
	level_update(tree->root, 0);

	print(tree->root);
}
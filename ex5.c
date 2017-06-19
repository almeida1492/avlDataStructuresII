#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "P8AVLADT.h"

int avl_height(AVL_TREE *tree, AVL_NODE *root){
	int leftHight, rightHight;

	if(root){
		leftHight = avl_hight(tree, root->left);
		rightHight = avl_hight(tree, root->right);
	
			if(leftHight < rightHight){
				return rightHight + 1;
			}
			else{
				return leftHight + 1;
		}
	}
	else{
		return -1;
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

void iterative_insertion(AVL_TREE *tree, int *data){
	AVL_NODE *pointer, *receiver;

	pointer = tree->root;
	for (int i = 0; i < avl_height(tree, tree->root); ++i){
		
		if(tree->compare(data, pointer->dataPtr) < 0){
			if(pointer->left){
				pointer = tree->root->left;	
			}
			else{
				receiver = (AVL_NODE*) malloc(sizeof(AVL_NODE));
				receiver->dataPtr = data;
				pointer->left = receiver;
			}
		}
		else if(tree->compare(data, pointer->dataPtr) > 0){
			if(pointer->right){
				pointer = tree->root->right;	
			}
			else{
				receiver = (AVL_NODE*) malloc(sizeof(AVL_NODE));
				receiver->dataPtr = data;
				pointer->right = receiver;
			}
		}
	}
}

int main(){
//	Local Definitions
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





	return 0;
}














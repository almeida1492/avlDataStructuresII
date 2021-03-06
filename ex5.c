#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "P8AVLADT.h"

int avl_height(AVL_TREE *tree, AVL_NODE *root){
	int leftHight, rightHight;

	if(root){
		leftHight = avl_height(tree, root->left);
		rightHight = avl_height(tree, root->right);
	
			if(leftHight < rightHight){
				return rightHight + 1;
			}
			else{
				return leftHight + 1;
		}
	}
	else{
		return 0;
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
	int bound;

	bound = avl_height(tree, tree->root);

	pointer = tree->root;
	for (int i = 0; i < bound; i++){
		
		if(tree->compare(data, pointer->dataPtr) < 0){
			if(pointer->left != NULL){
				pointer = pointer->left;	
			}
			else{
				receiver = (AVL_NODE*) malloc(sizeof(AVL_NODE));
				receiver->dataPtr = data;
				pointer->left = receiver;
				break;
			}
		}
		else if(tree->compare(data, pointer->dataPtr) > 0){
			if(pointer->right){
				pointer = pointer->right;	
			}
			else{
				receiver = (AVL_NODE*) malloc(sizeof(AVL_NODE));
				receiver->dataPtr = data;
				pointer->right = receiver;
				break;
			}
		}
	}
}

void print(AVL_NODE *root){

	if(root->right){
		print(root->right);
	}
	printf("(%i) %i %i\n", root->level, *(int*)root->dataPtr, root->bal);
	if(root->left){
		print(root->left);
	}
}

int main(){
//	Local Definitions
	AVL_TREE *tree;
	int array[] = {70, 60, 80, 50, 75, 65, 45};
	int *container, *data;

//	Statements
	tree = AVL_Create(compareInt);
	for (int i = 0; i < 7; ++i){
		container = (int*) malloc(sizeof(int));
		*container = array[i];

		AVL_Insert(tree, container);
	}
	level_update(tree->root, 0);

	data = (int*) malloc(sizeof(int));
	printf("Input data: ");
	scanf("%i", data);
	printf("\n");

	iterative_insertion(tree, data);
	level_update(tree->root, 0);
	
	print(tree->root);
	return 0;
}



// {70, 60, 80, 50, 75, 65, 45}










#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "P8AVLADT.h"

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

void* node_search(AVL_TREE* tree, void* keyPtr, AVL_NODE* root){
//	Statements 
	if(root){

		if(root->level == 1 && *(int*)root->dataPtr == *(int*)keyPtr){
			printf("\nNode is root, thus it has no parent\n");
			return NULL;
		}

		if(*(int*)root->left->dataPtr 	== *(int*)keyPtr 	||
		   *(int*)root->right->dataPtr 	== *(int*)keyPtr 	){

			printf("\nNode found at level %i carrying value [%i]\n", root->level, *(int*)root->dataPtr);
			return root->dataPtr;
		}
		
		if (tree->compare(keyPtr, root->dataPtr) < 0){
			if(root->left){
				return node_search(tree, keyPtr, root->left);
			}
	    	else{
	    		return NULL;
	    	}
	    }

	    else if (tree->compare(keyPtr, root->dataPtr) > 0){
	    	if(root->right){
	    		return node_search(tree, keyPtr, root->right);
	    	}
	        else{
	        	return NULL;
	        }
	    }

		return NULL;
	}  // if root 
	
	else{ // Data not in tree 
	    return NULL;
	}
}



int main(){
//	Local Definitions 
	AVL_TREE *tree;
	int array[] = {70, 60, 80, 50, 75, 65, 45};
	int *container, *val, *receiver;

//	Statements 
	tree = AVL_Create(compareInt);
	val = (int*) malloc(sizeof(int));
	for (int i = 0; i < 7; ++i){
		container = (int*) malloc(sizeof(int));
		*container = array[i];

		AVL_Insert(tree, container);
	}
	level_update(tree->root, 0);

	printf("\nType the value to be searched: ");
	scanf("%i", val);

	receiver = (int*) node_search(tree, val, tree->root);
	if(receiver == NULL){
		printf("\nNot found\n");
	}
	return 0;
}
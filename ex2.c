#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "P8AVLADT.h"

void print_avl_tree(void *dataPtr){
	/*printf("(%i) %i \n", );*/
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
	int array[] = {80, 70, 60, 45, 50, 65, 75};
	int *container;

//	Statements
	tree = AVL_Create(compareInt);
	for (int i = 0; i < 7; ++i){
		container = (int*) malloc(sizeof(int));
		*container = array[i];

		AVL_Insert(tree, container);
	}
	level_update(tree->root, -1);
}
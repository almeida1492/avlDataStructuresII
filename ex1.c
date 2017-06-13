#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "P8AVLADT.h"
#include "../tree/P7-BST-ADT.h"

int bst_hight(BST_TREE *tree, NODE *root){
	int leftHight, rightHight;

	if(root){
		leftHight = bst_hight(tree, root->left);
		rightHight = bst_hight(tree, root->right);
	
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

int avl_hight(AVL_TREE *tree, AVL_NODE *root){
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

int main(){
	//Declarations
	BST_TREE *bst_tree_rand, *bst_tree_best, *bst_tree_worst;
	AVL_TREE *avl_tree_rand, *avl_tree_best, *avl_tree_worst;
	int *bst_container, *avl_container, rand_receiver;

	//Statements
	bst_tree_rand 	= BST_Create(compareInt);
	bst_tree_best 	= BST_Create(compareInt);
	bst_tree_worst 	= BST_Create(compareInt);

	avl_tree_rand 	= AVL_Create(compareInt);
	avl_tree_best 	= AVL_Create(compareInt);
	avl_tree_worst 	= AVL_Create(compareInt);

	for (int i = 1; i <= 10000; i++){

		if (i <= 100){					//tree size = 100
			bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));	
			rand_receiver = rand()%10000;
			*bst_container = rand_receiver;
			*avl_container = rand_receiver;	
			BST_Insert(bst_tree_rand, bst_container);
			AVL_Insert(avl_tree_rand, avl_container); 

			/*bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));*/

			bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));
			*bst_container = i;
			*avl_container = i;
			BST_Insert(bst_tree_worst, bst_container);
			AVL_Insert(avl_tree_worst, avl_container);
			if (i == 100){
				printf("\n------------------------------------");
				printf("\n size 	= [%i]", i);
				printf("\n random case BST hight 	= %i", bst_hight(bst_tree_rand, bst_tree_rand->root));
				printf("\n random case AVL hight 	= %i\n", avl_hight(avl_tree_rand, avl_tree_rand->root));

				printf("\n worst case BST hight 	= %i", bst_hight(bst_tree_worst, bst_tree_worst->root));
				printf("\n worst case AVL hight 	= %i\n", avl_hight(avl_tree_worst, avl_tree_worst->root));
			}
		}


		if (i > 100 && i <= 500){		//tree size = 500
			bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));	
			rand_receiver = rand()%10000;
			*bst_container = rand_receiver;
			*avl_container = rand_receiver;	
			BST_Insert(bst_tree_rand, bst_container);
			AVL_Insert(avl_tree_rand, avl_container); 

			/*bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));*/

			bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));
			*bst_container = i;
			*avl_container = i;
			BST_Insert(bst_tree_worst, bst_container);
			AVL_Insert(avl_tree_worst, avl_container);
			
			if (i == 500){
				printf("\n------------------------------------");
				printf("\n size 	= [%i]", i);
				printf("\n random case BST hight 	= %i", bst_hight(bst_tree_rand, bst_tree_rand->root));
				printf("\n random case AVL hight 	= %i\n", avl_hight(avl_tree_rand, avl_tree_rand->root));

				printf("\n worst case BST hight 	= %i", bst_hight(bst_tree_worst, bst_tree_worst->root));
				printf("\n worst case AVL hight 	= %i\n", avl_hight(avl_tree_worst, avl_tree_worst->root));
			}
		}


		if (i > 500 && i <= 1000){		//tree size = 1000
			bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));	
			rand_receiver = rand()%10000;
			*bst_container = rand_receiver;
			*avl_container = rand_receiver;	
			BST_Insert(bst_tree_rand, bst_container);
			AVL_Insert(avl_tree_rand, avl_container); 

			/*bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));*/

			bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));
			*bst_container = i;
			*avl_container = i;
			BST_Insert(bst_tree_worst, bst_container);
			AVL_Insert(avl_tree_worst, avl_container);
			
			if (i == 1000){
				printf("\n------------------------------------");
				printf("\n size 	= [%i]", i);
				printf("\n random case BST hight 	= %i", bst_hight(bst_tree_rand, bst_tree_rand->root));
				printf("\n random case AVL hight 	= %i\n", avl_hight(avl_tree_rand, avl_tree_rand->root));

				printf("\n worst case BST hight 	= %i", bst_hight(bst_tree_worst, bst_tree_worst->root));
				printf("\n worst case AVL hight 	= %i\n", avl_hight(avl_tree_worst, avl_tree_worst->root));
			}
		}

		if (i > 1000 && i <= 5000){		//tree size = 5000
			bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));	
			rand_receiver = rand()%10000;
			*bst_container = rand_receiver;
			*avl_container = rand_receiver;	
			BST_Insert(bst_tree_rand, bst_container);
			AVL_Insert(avl_tree_rand, avl_container); 

			/*bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));*/

			bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));
			*bst_container = i;
			*avl_container = i;
			BST_Insert(bst_tree_worst, bst_container);
			AVL_Insert(avl_tree_worst, avl_container);
			if (i == 5000){
				printf("\n------------------------------------");
				printf("\n size 	= [%i]", i);
				printf("\n random case BST hight 	= %i", bst_hight(bst_tree_rand, bst_tree_rand->root));
				printf("\n random case AVL hight 	= %i\n", avl_hight(avl_tree_rand, avl_tree_rand->root));

				printf("\n worst case BST hight 	= %i", bst_hight(bst_tree_worst, bst_tree_worst->root));
				printf("\n worst case AVL hight 	= %i\n", avl_hight(avl_tree_worst, avl_tree_worst->root));
			}
		}


		if (i > 5000 && i <= 10000){	//tree size = 10000
			bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));	
			rand_receiver = rand()%10000;
			*bst_container = rand_receiver;
			*avl_container = rand_receiver;	
			BST_Insert(bst_tree_rand, bst_container);
			AVL_Insert(avl_tree_rand, avl_container); 

			/*bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));*/

			bst_container = (int*) malloc(sizeof(int));	
			avl_container = (int*) malloc(sizeof(int));
			*bst_container = i;
			*avl_container = i;
			BST_Insert(bst_tree_worst, bst_container);
			AVL_Insert(avl_tree_worst, avl_container);
			if (i == 10000){
				printf("\n------------------------------------");
				printf("\n size 	= [%i]", i);
				printf("\n random case BST hight 	= %i", bst_hight(bst_tree_rand, bst_tree_rand->root));
				printf("\n random case AVL hight 	= %i\n", avl_hight(avl_tree_rand, avl_tree_rand->root));

				printf("\n worst case BST hight 	= %i", bst_hight(bst_tree_worst, bst_tree_worst->root));
				printf("\n worst case AVL hight 	= %i\n", avl_hight(avl_tree_worst, avl_tree_worst->root));
			}
		}
	}

	return 0;
}
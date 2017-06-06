/*	================= AVL_Insert ===================	This function inserts new data into the tree.	   Pre    tree is pointer to AVL tree structure	   Post   data inserted or memory overflow 	   Return Success (true) or Overflow (false)*/bool AVL_Insert (AVL_TREE* tree, void* dataInPtr){//	Local Definitions 	AVL_NODE* newPtr;	bool  forTaller;//	Statements 	newPtr = (AVL_NODE*)malloc(sizeof(AVL_NODE));	if (!newPtr)	   return false;	newPtr->bal     = EH;	newPtr->right   = NULL;	newPtr->left    = NULL;	newPtr->dataPtr = dataInPtr;   	tree->root = _avl_insert(tree, tree->root, newPtr, &forTaller);	(tree->count)++;	return true;}  // AVL_Insert 
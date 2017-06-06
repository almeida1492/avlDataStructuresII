/*	===================== _retrieve ===================== 	Searches tree for node containing requested key 	and returns its data to the calling function.	   Pre     AVL_Retrieve passes tree, keyPtr, root 	           keyPtr is pointer to data structure 	              containing key to be located 	   Post    tree searched; data pointer returned 	   Return  Address of matching node returned 	            If not found, NULL returned */void* _avl_retrieve (AVL_TREE* tree, void* keyPtr, AVL_NODE* root){//	Statements 	if (root)	    {	     if (tree->compare(keyPtr, root->dataPtr) < 0)	         return _avl_retrieve(tree, keyPtr, root->left);	     else if (tree->compare(keyPtr, root->dataPtr) > 0)	         return _avl_retrieve(tree, keyPtr, root->right);	     else	         // Found equal key 	         return root->dataPtr;	    }  // if root 	else	    // Data not in tree 	    return NULL;}	// _retrieve 
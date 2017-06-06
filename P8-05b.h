/* ===================== insRightBal ===================== 
	Tree out-of-balance to the right. This function 
	rotates the tree to the left.
	   Pre  The tree is right high 
	   Post Balance restored; returns potentially new root
*/
	AVL_NODE* insRightBal (AVL_NODE* root, bool* taller) 
{
//	Local Definitions 
	AVL_NODE* rightTree;
	AVL_NODE* leftTree;

//	Statements 
	rightTree = root->right;
	switch (rightTree->bal)
	   {
	    case RH: // Left High--Rotate Right 
	             root->bal     = EH;
	             rightTree->bal = EH;
	             
	             // Rotate Right 
	             root     = rotateLeft (root);
	             *taller  = false;
	             break;
	    case EH: // This is an error 
	             printf ("\n\aError in insRightBal\n");
	             exit (100); 
	    case LH: // Left High-Requires double 
	             // rotation: first right, then left 
	             leftTree = rightTree->left;
	             switch (leftTree->bal)
	                {
	                 case RH: root->bal     = LH;
	                          rightTree->bal = EH;
	                          break;
	                 case EH: root->bal     = EH;
	                          rightTree->bal = EH;
	                          break;
	                 case LH: root->bal     = EH;
	                          rightTree->bal = RH;
	                          break;
	                } // switch rightTree 
	             
	             leftTree->bal = EH;
	             // Rotate Right 
	             root->right = rotateRight (rightTree);
	             
	             // Rotate Left 
	             root     = rotateLeft (root);
	             *taller  = false;
	   } // switch 
	return root;
}	// insRightBal 

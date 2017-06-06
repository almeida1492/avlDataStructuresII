/*	=================== dltRightBal ==================  
	The tree is shorter after a delete on the right. This 
	function adjusts the balance factors and rotates the tree 
	to the right if necessary.
	   Pre     tree shorter 
	   Post    Balance factors reset-balance restored 
	   Returns potentially new root 
*/
AVL_NODE* dltLeftBal (AVL_NODE* root, bool* shorter)
{
//	Local Definitions 
	AVL_NODE* rightTree;
	AVL_NODE* leftTree;
	
//	Statements 
	switch (root->bal)
	    {
	     case RH:       // Deleted Right--Now balanced 
	          root->bal  = EH;
	          break;
	          
	     case EH:       // Now Left high 
	          root->bal  = LH;
	          *shorter   = false;
	          break;
	          
	     case LH:       // Left High - Rotate Right
	          leftTree = root->left;
	          if (leftTree->bal == RH)
	              // Double rotation required 
	              {
	               rightTree  = leftTree->right;
	               
	               switch (rightTree->bal)
	                   {
	                    case RH: leftTree->bal = LH;
	                             root->bal      = EH;
	                             break;
	                    case EH: root->bal      = EH;
	                             leftTree->bal = EH;
	                             break;
	                    case LH: root->bal      = RH;
	                             leftTree->bal = EH;
	                             break;
	                   } // switch 
	                   
	               rightTree->bal = EH;
	               
	               // Rotate Left then Right 
	               root->left = rotateLeft (leftTree);
	               root = rotateRight(root);
	              } // if leftTree->bal == RH 
	          else
	              {
	               // Single Rotation Only 
	               switch (leftTree->bal)
	                   {
	                    case RH:
	                    case LH: root->bal      = EH;
	                             leftTree->bal = EH;
	                             break;
	                    case EH: root->bal      = LH;
	                             leftTree->bal = RH;
	                             *shorter       = false;
	                             break;
	                   } // switch leftTree->bal 
	               root = rotateRight(root);
	              } // else 
	    } // switch 
	return root;
}	// dltLeftBal 

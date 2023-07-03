// Recursive Approach
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	if(root == NULL) return NULL;
    int cur = root->data;
    if(cur < p->data && cur < q->data){
        return LCAinaBST(root->right, p, q);
    }
    if(cur > p->data && cur > q->data){
        return LCAinaBST(root->left, p, q);
    }
    return root;
}
/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where N is the total number of nodes of the BST.
*/


// Beter Approach: Iterative
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	while(root != NULL){
        if(root->data < p->data && root->data < q->data){
            root = root->right;
        }
        else if(root->data > p->data && root->data > q->data){
            root = root->left;
        }
        else{
            return root;
        }
    }
}

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where N is the total number of nodes of the BST.
*/

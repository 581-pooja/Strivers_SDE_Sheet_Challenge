// Iterative Approach
bool searchInBST(BinaryTreeNode<int> *root, int val) {
    while(root != NULL){
        if(root->data == val) return true;
        root = val > root->data ? root->right: root->left;
    }
    return false;
}


// Iterative Approach
bool searchInBST(BinaryTreeNode<int> *root, int val) {
    BinaryTreeNode<int> *ptr = root;

    while(ptr != NULL){
        if(ptr->data == val) return true;
        if(ptr->data > val){
            ptr = ptr->left;
        }
        else{
            ptr = ptr->right;
        }
    }
    return false;
}

/*
    Time Complexity : O(H)
    Space Complexity : O(1)

    Where 'H' is the height of the given BST.
*/

// Recursive Approach

bool searchInBST(BinaryTreeNode<int> *root, int val) {
    if(root == NULL) return false;
    if(root->data == val) return true;
    if(root->data < val) {
        // Recursively check for right subtree. 
        return searchInBST(root->right, val);
    }
    else{
        // Recursively check for left subtree. 
        return searchInBST(root->left, val);
    }
}
/*
    Time Complexity : O(H)
    Space Complexity : O(H)

    Where 'H' is the height of the given BST.
*/

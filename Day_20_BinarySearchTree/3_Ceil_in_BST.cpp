
int findCeil(BinaryTreeNode<int> *root, int key){
    int ceil = -1;
    while(root){
        if(root->data == key){
            ceil = root->data;
            return ceil;
        }
        if(key < root->data){
            ceil = root->data;
            root = root->left;
        }
        else{
            // key > root->data
            root = root->right;
        }
    }
    return ceil;
}
/*
    Time Complexity : O(H)
    Space Complexity : O(1)
    Where 'H' is the height of the given BST.
*/

int dfsHeight(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;

    int lh = dfsHeight(root->left);
    if(lh == -1) return -1;

    int rh = dfsHeight(root->right);
    if(rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    return dfsHeight(root) != -1;
}

bool isValid(BinaryTreeNode<int> *root, long minVal, long maxVal){
    if(root == NULL) return true;

    if(root->data >= maxVal || root->data <= minVal) return false;

    return isValid(root->left, minVal, root->data) && isValid(root->right, root->data, maxVal);
}


bool validateBST(BinaryTreeNode<int> *root) {
    return isValid(root, INT_MIN, INT_MAX);
}

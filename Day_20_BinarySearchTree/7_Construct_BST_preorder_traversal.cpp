
TreeNode<int>* bulid(vector<int> &preorder, int &i, int bound ){
    if(i == preorder.size() || preorder[i] > bound) return NULL;

    TreeNode<int>* root = new TreeNode<int> (preorder[i++]);
    
    root->left = bulid(preorder, i,root->data);
    root->right = bulid(preorder, i, bound);
}

TreeNode<int>* preOrderTree(vector<int> &preorder){
    int i=0;
    return bulid(preorder, i, INT_MAX);
}

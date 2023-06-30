// using Recursion
void preorder(TreeNode *node, vector<int> &ans){
    if(node == NULL) return ;
    // root - left - right
    ans.push_back(node->data);
    preorder(node->left, ans);
    preorder(node->right, ans);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    preorder(root, ans);
    return ans;   
}
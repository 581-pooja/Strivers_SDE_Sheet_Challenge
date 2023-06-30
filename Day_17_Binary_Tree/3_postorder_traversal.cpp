// using Recursion
void postorder(TreeNode *node, vector<int> &ans){
    if(node == NULL) return ;
    // left - right - root
    postorder(node->left, ans);
    postorder(node->right, ans);
    ans.push_back(node->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    postorder(root, ans);
    return ans;   
}
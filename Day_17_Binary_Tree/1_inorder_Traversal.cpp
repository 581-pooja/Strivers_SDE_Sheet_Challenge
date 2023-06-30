// using Recursion
void inorder(TreeNode *node, vector<int> &ans){
    if(node == NULL) return ;
    inorder(node->left, ans);
    ans.push_back(node->data);
    inorder(node->right, ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    inorder(root, ans);
    return ans;   
}
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

// Using Iterative Approach:

vector<int> getInOrderTraversal(TreeNode *root)
{
    stack <TreeNode*> st;
    TreeNode *node = root;
    vector<int> inorder;
    
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty() == true) break; // edge case to get out of while loop
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}
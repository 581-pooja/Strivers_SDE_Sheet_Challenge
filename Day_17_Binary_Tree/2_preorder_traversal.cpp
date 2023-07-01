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

// Using Iterative Approach:

vector<int> getPreOrderTraversal(TreeNode *root)
{
    stack <TreeNode*> st;
    TreeNode *node = root;
    vector<int> preorder;
    
    while(true){
        if(node != NULL){
            preorder.push_back(node->data);
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty() == true) break; // edge case to get out of while loop
            node = st.top();
            st.pop();
            node = node->right;
        }
    }
    return preorder;
}



vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector <int> preorder;
    if(root == NULL) return preorder;
    stack <TreeNode*> st;
    st.push(root);
    
    while(!st.empty()){
        root = st.top();
        st.pop();
        preorder.push_back(root->data);

        if(root->right != NULL){
            st.push(root->right);
        }
        
        if(root->left != NULL){
            st.push(root->left);
        }
    }
    return preorder;
}
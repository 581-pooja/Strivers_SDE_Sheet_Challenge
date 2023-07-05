// Brute Force:
class BSTiterator
{
    public:
    vector<int> inorder;
    int count = 0;
    void inorderTraversal(TreeNode<int>* root){
        if(root == NULL) return;
        inorderTraversal(root->left);
        inorder.push_back(root->data);
        inorderTraversal(root->right);
    }

    BSTiterator(TreeNode<int> *root)
    {
        inorderTraversal(root);
    }

    int next()
    {
        return inorder[count++];
    }

    bool hasNext()
    {
        if(count < inorder.size()) return true;
        return false;
    }
};

// Optimal Approach:
class BSTiterator
{
    public:
    stack <TreeNode<int>*> st;

    void pushAll(TreeNode<int>* node){
        if(!node) return;
        while(node != NULL){
            st.push(node);
            node = node->left;
        }
    }
    
    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode<int>* tempNode = st.top();
        st.pop();
        pushAll(tempNode->right);
        return tempNode->data;
    }

    bool hasNext()
    {
        if(st.empty()) return false;
        return true;
    }
};

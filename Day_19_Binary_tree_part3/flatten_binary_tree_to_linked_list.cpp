/*
Given the root of a binary tree, flatten the tree into a "linked list":
    The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree
*/


TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(root == NULL) return NULL;
    
    stack <TreeNode<int> *> s;
    s.push(root);
    
    while(!s.empty()){
        auto cur = s.top();
        s.pop();
        
        if(cur->right){
            s.push(cur->right);
        }
        if(cur->left){
            s.push(cur->left);
        }
        if(!s.empty()){
            cur->right = s.top();
        }

        cur->left = NULL;
    }
    return root;
}


class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL){
            return ;
        }
        // we will do reverse preorder i.e. Right Left Root
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
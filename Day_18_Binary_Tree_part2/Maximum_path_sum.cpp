/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
    
    int maxPathDown(TreeNode* root , int &maxi){
        if(!root) return 0;
        int left = max(0, maxPathDown(root->left,maxi)); // zero will prevent us by taking negative path
        int right = max(0, maxPathDown(root->right, maxi));
        // backtracking
        maxi = max(maxi, root->val + left + right);
        return max(left, right) + root->val;
    }
};
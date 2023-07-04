
// inorder -> recursive traversal
void inorder(TreeNode<int> *root, int &count, int k, int &ans){
    if(!root) return;
    inorder(root->left, count, k, ans);
    count++;
    if(k == count) ans = root->data;
    inorder(root->right, count, k, ans);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    int count = 0;
    int ans;
	// Inorder of BST is sorted
    inorder(root, count, k, ans);

    return ans;
}


// inorder -> Iterative traversal

# include <bits/stdc++.h>
TreeNode<int>* buildTree(vector<int> &postorder, int postStart, int postEnd, 
vector<int> &inorder, int inStart, int inEnd, map<int,int> inMap){
    // Base cases
    if(postStart > postEnd || inStart > inEnd) return NULL;
    
    TreeNode<int>* root = new TreeNode<int> (postorder[postEnd]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(postorder, postStart , postStart + numsLeft - 1, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, inMap);
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	map <int,int> inMap;
    // assigning indexs to inorder array
    for(int i=0; i<inorder.size(); i++){
        inMap[inorder[i]] = i;
    }
    
    TreeNode<int>* root = buildTree(postorder, 0, postorder.size() - 1, 
    inorder, 0, inorder.size() - 1, inMap);
    return root;
}

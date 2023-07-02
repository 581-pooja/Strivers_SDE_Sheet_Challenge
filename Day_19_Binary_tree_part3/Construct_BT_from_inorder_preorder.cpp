
TreeNode<int>* buildTree(vector<int> &preorder, int preStart, int preEnd, 
vector<int> &inorder, int inStart, int inEnd, map<int,int> inMap){
    // Base cases
    if(preStart > preEnd || inStart > inEnd) return NULL;
    
    TreeNode<int>* root = new TreeNode<int> (preorder[preStart]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	map <int,int> inMap;
    // assigning indexs to inorder array
    for(int i=0; i<inorder.size(); i++){
        inMap[inorder[i]] = i;
    }
    
    TreeNode<int>* root = buildTree(preorder, 0, preorder.size() - 1, 
    inorder, 0, inorder.size() - 1, inMap);
    return root;
}

// Other Method:


TreeNode<int>* buildTree(vector<int>& inorder, vector<int>& preorder, int& rootIndex, int left, int right)
{
    if(left > right)
        return NULL;
    
    int inorderIndex = left;
    while(inorder[inorderIndex] != preorder[rootIndex])
        inorderIndex++;

    TreeNode<int>* node = new TreeNode<int>(preorder[rootIndex]);
    rootIndex++;

    node->left = buildTree(inorder, preorder, rootIndex, left, inorderIndex-1);
    node->right = buildTree(inorder, preorder, rootIndex, inorderIndex+1, right);

    return node;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	int rootIndex = 0;

    return buildTree(inorder, preorder, rootIndex, 0, preorder.size()-1);
}
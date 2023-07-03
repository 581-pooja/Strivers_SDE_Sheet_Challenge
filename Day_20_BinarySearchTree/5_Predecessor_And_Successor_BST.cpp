// brute Force:

void inorder(BinaryTreeNode<int>* root, vector<int> &inorderArray){
    if(root == NULL) return;
    inorder(root->left, inorderArray);
    inorderArray.push_back(root->data);
    inorder(root->right, inorderArray);
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    vector <int> inorderArray;
    inorder(root, inorderArray);
    
    int predecessor = -1;
    int successor = -1;
    
    for(int i=0;i<inorderArray.size(); i++){
        if(inorderArray[i] == key){
            if(i-1 >= 0) predecessor = inorderArray[i-1];
            if(i+1 < inorderArray.size()){
                successor = inorderArray[i+1];
            }
            break;
        }
    }
    
    return {predecessor, successor};
}

// Optimal Approach:

int inorderPredecessor(BinaryTreeNode<int>* root, int key){
    int predecessor = -1;
    while(root != NULL){
        if(key <= root->data){
            root = root->left;
        }
        else{
            predecessor = root->data;
            root = root->right;
        }
    }
    return predecessor;
}

int inorderSuccessor(BinaryTreeNode<int>* root, int key){
    int successor = -1;
    while(root != NULL){
        if(key >= root->data){
            root = root->right;
        }
        else{
            successor = root->data;
            root = root->left;
        }
    }
    return successor;
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    return {inorderPredecessor(root, key), inorderSuccessor(root, key)};
}
// TC: O(N) | SC: O(1)


//  Other:

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int predecessor = -1;
    int successor = -1;

    // Reach to the key.
    while (root -> data != key)
    {
        if (key > root -> data)
        {
            predecessor = root -> data;
            root = root -> right;
        }
        else
        {
            successor = root -> data;
            root = root -> left;
        }
    }

    BinaryTreeNode<int>* rightSubtree = root -> right;
    
    while (rightSubtree != NULL)
    {
        successor = rightSubtree -> data;
        rightSubtree = rightSubtree -> left;
    }

    BinaryTreeNode<int>* leftSubtree = root -> left;

    while (leftSubtree != NULL)
    {
        predecessor = leftSubtree -> data;
        leftSubtree = leftSubtree -> right;
    }

    return {predecessor, successor};
}

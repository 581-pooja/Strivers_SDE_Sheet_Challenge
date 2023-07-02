/*
Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the tree holds the Children sum property
A binary tree is said to follow the children sum property if, for every node of that tree, the value of that node is equal to the
 sum of the value(s) of all of its children nodes( left child and the right child).
*/

void changeTree(BinaryTreeNode < int > * root) {
    if(root == NULL) return;
    int child = 0;
    if(root->left){
        child += root->left->data;
    }
    if(root->right){
        child += root->right->data;
    }

    if(child >= root->data){
        root->data = child;
    }
    else{
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }

    changeTree(root->left); 
    changeTree(root->right); 

    // backtracking
    int total = 0;
    if(root->left){
        total += root->left->data;
    }
    if(root->right){
        total += root->right->data;
    }
    if(root->left || root->right){
        root->data = total;
    }
}  
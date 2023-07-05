
class BSTIterator{
    stack <BinaryTreeNode<int>* > st;
    // reverse -> true -> before
    // reverse -> false -> next
    bool reverse = true;
    
    public:
    BSTIterator(BinaryTreeNode<int> *root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        BinaryTreeNode<int>* tempNode = st.top();
        st.pop();
        if(reverse == false) pushAll(tempNode->right);
        else pushAll(tempNode->left);
        return tempNode->data;
    }

    void pushAll(BinaryTreeNode<int> *node){
        while(node != NULL){
            st.push(node);
            if(reverse == true){
                node = node->right;  // before(j)
            }
            else{
                node = node->left;   // next(i)
            }
        }
    }
    
};


bool pairSumBst(BinaryTreeNode<int> *root, int k){
    if(!root) return false;
    // next -- Left
    BSTIterator L(root, false);
    // for before -- right
    BSTIterator R(root, true);
    int i = L.next();
    int j = R.next();
    while(i<j){
        if(i+j == k) return true;
        else if(i+j < k) i = L.next();
        else j = R.next();
    }
    return false;
}


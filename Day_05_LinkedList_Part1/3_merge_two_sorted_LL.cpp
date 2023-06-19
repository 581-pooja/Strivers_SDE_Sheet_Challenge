Node<int>* sortTwoLists(Node<int>*l1, Node<int>* l2)
{
    // Brute Force: using external LL or space
    Node<int> *dummy = new Node<int>(0);
    Node<int> *temp;
    temp = dummy;

    while(l1 != NULL && l2 != NULL){
        if(l1->data < l2->data){
            temp->next = l1;
            l1 = l1->next;
        }
        else{
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    if(l1 != NULL) temp->next = l1;
    if(l2 != NULL) temp->next = l2;
    return dummy->next;
}

// TC: O(N+M) | SC: O(N+M)

Node<int>* sortTwoLists(Node<int>*l1, Node<int>* l2)
{
    // Optimal Approach: Inplace Method
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    if(l1->data > l2->data) {
        swap(l1, l2);
    }
    Node<int> *res = l1;

    while(l1 != NULL && l2 != NULL){
        Node<int>* temp = NULL;
        while(l1 && l1->data <= l2->data){
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }
    return res;
}
// TC: O(N+M) | SC: O(1)
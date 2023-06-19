Node *findMiddle(Node *head) {
    int n=1;
    Node* temp = head;
    // Get the length of LL
    while(temp->next != NULL){
        temp = temp->next;
        n++;
    }

    // Traversing again LL till n/2 to get Middle of LL
    temp = head;
    for(int i=0; i<n/2; i++){
        temp = temp->next;
    }
    return temp;
}

// TC: O(N) + O(N/2) | SC: O(1)

// Slow & fast Approach
Node *findMiddle(Node *head) {
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// TC: O(N/2) | SC: O(1)
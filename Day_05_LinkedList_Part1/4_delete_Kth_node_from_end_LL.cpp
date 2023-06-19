// Brute Force:
Node* removeKthNode(Node* head, int k)
{
    if(k == 0) return head;
    Node* temp = head;
    // Get length of LL
    int counter = 0;
    while(temp != NULL){
        temp = temp->next;
        counter++;
    }
    // Calculating node to delete from front
    int N = counter - k;
    int count = 1;
    temp = head; // reinitailizing

    if(N == 0) head = head->next;
    else{
        // deleting Nth node from front
        while(count != N){
            temp = temp->next;
            count++;
        }
        temp->next = temp->next->next;
    }
  return head;
}

// Tc: O(N) + O(N) | SC: O(1)


// Optimized method : slow-fast pointer
Node* removeKthNode(Node* head, int k)
{
    // Intialize new dummy Node i.e. start
    Node* start = new Node();
    start->next = head;
    
    // Initialize two pointers slow & fast
    Node* slow = start;
    Node* fast = start;
    
    // Move fast pointer till the kth node
    for(int i=1; i<=k; i++){
        fast = fast->next;
    }

    // Move both pointer simultaneously 
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return start->next;
}

// TC: O(N) | SC: O(1)
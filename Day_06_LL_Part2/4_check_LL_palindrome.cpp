// Brute Force: Using extra space i.e. array to store elements
bool isPalindrome(LinkedListNode<int> *head) {
    vector<int> arr;
    while(head != NULL){
        arr.push_back(head->data);
        head = head->next;
    }
    for(int i=0; i<(arr.size()/2); i++){
        if(arr[i] != arr[arr.size()-i-1]){
            return false;
        }
    }
    return true;
}
// Tc: O(N) | SC: O(N)

// Optimal Approach:
LinkedListNode<int>* reverseList(LinkedListNode<int>* head) {
    LinkedListNode<int> *newHead = NULL;
    while (head != NULL) {
        LinkedListNode<int> *next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}


bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL) return true;

    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseList(slow->next);
    slow = slow->next;

    LinkedListNode<int>* dummy = head;
    while(slow != NULL){
        if(dummy->data != slow->data) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}

// Tc: O(N) | Sc: O(1)
// brute force:
Node *firstNode(Node *head)
{
    unordered_set <Node*> hashTable;
    while(head != NULL){
        if(hashTable.find(head) != hashTable.end()) return head;
        hashTable.insert(head);
        head = head->next;
    }
    return NULL;
}
// TC: O(N) | SC: O(N)

// Optimized force:
Node *firstNode(Node *head)
{
    if(head == NULL || head->next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    Node* entry = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            while(slow != entry){
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    return NULL;
}
// Tc: O(N) | Sc: O(1)
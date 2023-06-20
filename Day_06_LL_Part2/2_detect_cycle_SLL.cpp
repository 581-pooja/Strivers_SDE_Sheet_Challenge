// Brute Force : using hashTable or unorderd_set 
#include <bits/stdc++.h>
bool detectCycle(Node *head)
{
	unordered_set <Node*> hashTable;
    while(head != NULL){
        if(hashTable.find(head) != hashTable.end()){
            return true;
        }
        hashTable.insert(head);
        head = head->next;
    }
    return false;
}
// TC: O(N) | SC: O(N)

// Optimal Approach
bool detectCycle(Node *head)
{
	if(head == NULL) return false;
    Node* fast = head;
    Node* slow = head;
    
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;
}
// TC: O(N) | SC: O(1)
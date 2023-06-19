/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        while (head != NULL) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
};

// CodeStudio

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL) return head;
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *cur = head;
    LinkedListNode<int> *forward = NULL;

    while(cur != NULL){
        forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
    }
    return prev;
}

// Tc: O(N) | SC: O(1)
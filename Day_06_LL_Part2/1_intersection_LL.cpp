// brute Force:
Node* findIntersection(Node *head1, Node *head2)
{
    while(head2 != NULL){
        Node* temp = head1;
        while(temp != NULL){
            if(temp == head2){
                return head2;
            }
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
}
// TC: O(m*n) | SC: O(1)


// Better Approach:
#include<bits/stdc++.h>
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    unordered_set <Node*> st;
    while(firstHead != NULL){
        st.insert(firstHead);
        firstHead = firstHead->next;
    }

    while(secondHead != NULL){
        if(st.find(secondHead) != st.end()) return secondHead;
        secondHead = secondHead->next;
    }
    return NULL;
}
// TC: O(m+n) | SC: O(n)

// Optimized approach:
int getDifference(Node* head1, Node* head2){
    int len1 = 0;
    int len2 = 0;
    while(head1 || head2){
        if(head1){
            len1++;
            head1 = head1->next;
        }
        if(head2){
            len2++;
            head2 = head2->next;
        }
    }
    return len1-len2;
}
Node* findIntersection(Node *head1, Node *head2)
{
    int diff = getDifference(head1, head2);
    if(diff < 0){
        while(diff != 0){
            head2 = head2->next;
            diff++;
        }
    }
    else{
        while(diff != 0){
            head1 = head1->next;
            diff--;
        }
    }
    
    while(head1 != NULL){
        if(head1 == head2){
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}
// TC: O(2*m) | SC: O(1)


// Optimized approach:
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    if(firstHead == NULL || secondHead == NULL) return NULL;
    Node* a = firstHead;
    Node* b = secondHead;
    
    while(a != b){
        a = a == NULL ? secondHead: a->next;
        b = b == NULL ? firstHead : b->next;
    }
    return a;
}
// TC: O(2*(max(m,n))) | SC: O(1)

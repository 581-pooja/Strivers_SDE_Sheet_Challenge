void deleteNode(LinkedListNode<int> * node) {
    node->data = node->next->data;
    node->next = node->next->next;
}
// TC: O(1) | SC: O(1)
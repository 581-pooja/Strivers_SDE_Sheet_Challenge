
Node* mergeTwoLists(Node* a, Node* b){
	Node* temp = new Node(0);
	Node* res = temp;
	while(a != NULL && b != NULL){
		if(a->data < b->data){
			temp->child = a;
			temp = temp->child;
			a = a->child;
		}
		else{
			temp->child = b;
			temp = temp->child;
			b = b->child;
		}
	}
	if(a != NULL) temp->child = a;
	else temp->child = b;
	return res->child;
}


Node* flattenLinkedList(Node* root) 
{
	if(root == NULL || root->next == NULL) return root;
	Node* L2 = flattenLinkedList(root->next);
	root->next = NULL;
	root = mergeTwoLists(root, L2);
	return root;
}

// Tc: O(N) | SC: O(1)
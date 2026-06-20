// Time Complexity: O(N * M)
// Space Complexity: O(N)
// Explanation: Recursively flatten the `next` list, then merge the current list (`bottom` pointers) with the flattened `next` list, similar to merging two sorted linked lists.

Node* mergeTwoLists(Node* a, Node* b) {
    Node* temp = new Node(0);
    Node* res = temp;
    while(a != NULL && b != NULL) {
        if(a->data < b->data) { temp->bottom = a; temp = temp->bottom; a = a->bottom; }
        else { temp->bottom = b; temp = temp->bottom; b = b->bottom; }
    }
    if(a) temp->bottom = a;
    else temp->bottom = b;
    return res->bottom;
}
Node *flatten(Node *root) {
    if(root == NULL || root->next == NULL) return root;
    root->next = flatten(root->next);
    root = mergeTwoLists(root, root->next);
    return root;
}


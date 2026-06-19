// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Reverse the linked list. Keep track of the max node seen so far. If a node is less than the max node, delete it. Else, update max node. Finally, reverse the list back.

Node *reverse(Node *head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *compute(Node *head) {
    head = reverse(head);
    Node *curr = head;
    Node *maxNode = head;
    while(curr != NULL && curr->next != NULL) {
        if(curr->next->data < maxNode->data) {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
            maxNode = curr;
        }
    }
    return reverse(head);
}


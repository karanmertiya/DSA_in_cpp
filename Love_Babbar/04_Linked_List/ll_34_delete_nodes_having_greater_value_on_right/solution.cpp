// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Reverse the linked list. Traverse the reversed list and keep track of the maximum value seen so far. If a node's value is less than the maximum, delete it. Otherwise, update the maximum. Finally, reverse the list again.

Node* reverseList(Node* head) {
    Node* prev = NULL, *curr = head, *next = NULL;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *compute(Node *head) {
    head = reverseList(head);
    Node* curr = head;
    int max_val = head->data;
    while(curr && curr->next) {
        if(curr->next->data < max_val) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
            max_val = curr->data;
        }
    }
    return reverseList(head);
}


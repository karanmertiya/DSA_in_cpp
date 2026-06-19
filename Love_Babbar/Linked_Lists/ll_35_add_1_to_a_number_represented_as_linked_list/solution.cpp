// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Reverse the linked list. Add 1 to the first node, and propagate the carry if the value becomes 10. Once done, reverse the list back. If carry still remains at the end, add a new node.

Node* reverseList(Node* head) {
    Node* curr = head, *prev = NULL, *next = NULL;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node* addOne(Node *head) {
    head = reverseList(head);
    Node* curr = head, *prev = NULL;
    int carry = 1;
    while(curr) {
        int sum = curr->data + carry;
        carry = sum / 10;
        curr->data = sum % 10;
        prev = curr;
        curr = curr->next;
    }
    if(carry > 0) prev->next = new Node(carry);
    return reverseList(head);
}


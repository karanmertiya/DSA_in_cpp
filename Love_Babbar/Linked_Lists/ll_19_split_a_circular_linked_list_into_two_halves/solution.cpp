// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use slow and fast pointers to find the mid of the circular linked list. The slow pointer will point to the mid. Then break the list into two and make both circular.

void splitList(Node *head, Node **head1_ref, Node **head2_ref) {
    Node *slow = head, *fast = head;
    if(head == NULL) return;
    while(fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next->next == head) fast = fast->next;
    *head1_ref = head;
    if(head->next != head) *head2_ref = slow->next;
    fast->next = slow->next;
    slow->next = head;
}


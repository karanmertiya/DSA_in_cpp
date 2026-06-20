// Time Complexity: O(N + M)
// Space Complexity: O(N + M)
// Explanation: Use two pointers, `ptr1` for the first list and `ptr2` for the second. If `ptr1->data < ptr2->data`, `ptr1++`. If `ptr2->data < ptr1->data`, `ptr2++`. If they are equal, add to the result list and advance both.

Node* findIntersection(Node* head1, Node* head2) {
    Node* dummy = new Node(0), *temp = dummy;
    Node* p1 = head1, *p2 = head2;
    while(p1 && p2) {
        if(p1->data < p2->data) p1 = p1->next;
        else if(p2->data < p1->data) p2 = p2->next;
        else {
            temp->next = new Node(p1->data);
            temp = temp->next;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return dummy->next;
}


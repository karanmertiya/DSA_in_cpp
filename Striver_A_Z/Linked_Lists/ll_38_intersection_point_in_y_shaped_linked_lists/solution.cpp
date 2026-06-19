// Time Complexity: O(N + M)
// Space Complexity: O(1)
// Explanation: Use two pointers `a` and `b`. Traverse both lists. When `a` reaches the end, redirect it to `head2`. When `b` reaches the end, redirect it to `head1`. They will meet at the intersection point or both become NULL.

int intersectPoint(Node* head1, Node* head2) {
    Node* a = head1, *b = head2;
    while(a != b) {
        a = (a) ? a->next : head2;
        b = (b) ? b->next : head1;
    }
    if(a) return a->data;
    return -1;
}


// Time Complexity: O(N + M)
// Space Complexity: O(1)
// Explanation: Two pointers. Pointer A traverses list A, then jumps to list B. Pointer B traverses list B, then jumps to list A. They traverse the same total distance (A+B) and will meet at the intersection, or at NULL.

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) return NULL;
    ListNode *a = headA, *b = headB;
    while(a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}


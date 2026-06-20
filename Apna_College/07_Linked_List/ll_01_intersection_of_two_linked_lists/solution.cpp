// Time Complexity: O(N + M)
// Space Complexity: O(1)
// Explanation: Two pointers `a` and `b`. Traverse `A` then `B`, and `B` then `A`. They will meet at the intersection node or `NULL`.

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA, *b = headB;
    while(a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}


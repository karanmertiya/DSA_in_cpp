// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Find length of list. Traverse groups of size k. For each group, perform standard linked list reversal. Link the prev group's tail to the current reversed head.

ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || k==1) return head;
    int count = 0; ListNode* dummy = new ListNode(0); dummy->next = head;
    ListNode *cur = head, *nex, *pre = dummy;
    while(cur) { count++; cur = cur->next; }
    while(count >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1; i<k; i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        count -= k;
    }
    return dummy->next;
}


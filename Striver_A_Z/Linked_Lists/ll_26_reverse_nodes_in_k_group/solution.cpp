// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Count nodes. While `count >= k`, reverse `k` nodes. Keep track of previous group's tail to connect to current group's head. If `< k` nodes remain, just connect them.

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL || k == 1) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *cur = dummy, *nex = dummy, *pre = dummy;
    int count = 0;
    while(cur->next != NULL) {
        cur = cur->next;
        count++;
    }
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


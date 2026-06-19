// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Compute length `N` of list. Connect tail to head to form a cycle. Find `k = k % N`. Move `N - k` steps from head. The new head is `current->next`. Break the cycle by setting `current->next = NULL`.

ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next || k == 0) return head;
    ListNode* cur = head;
    int len = 1;
    while(cur->next && ++len) cur = cur->next;
    cur->next = head;
    k = k % len;
    k = len - k;
    while(k--) cur = cur->next;
    head = cur->next;
    cur->next = NULL;
    return head;
}


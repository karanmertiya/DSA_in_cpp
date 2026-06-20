// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Compute the length of the list, and make it a circular list by connecting the last node to head. Then find the new break point `(length - k % length)`. Break the circle and return the new head.

ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next || k == 0) return head;
    int len = 1;
    ListNode* cur = head;
    while(cur->next) {
        len++;
        cur = cur->next;
    }
    cur->next = head;
    k = k % len;
    k = len - k;
    while(k--) cur = cur->next;
    head = cur->next;
    cur->next = NULL;
    return head;
}


// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use a dummy node. Maintain a `prev` pointer. While `prev->next` and `prev->next->next` exist, swap them and move `prev` two steps ahead.

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    while(prev->next && prev->next->next) {
        ListNode* first = prev->next;
        ListNode* second = prev->next->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
    }
    return dummy->next;
}


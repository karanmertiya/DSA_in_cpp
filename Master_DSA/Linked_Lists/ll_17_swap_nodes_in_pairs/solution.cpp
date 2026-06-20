// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use a dummy node. Iteratively swap `curr` and `curr->next`. Keep track of `prev` to link the swapped pairs to the rest of the list.

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    while(prev->next != NULL && prev->next->next != NULL) {
        ListNode* first = prev->next;
        ListNode* second = prev->next->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
    }
    return dummy->next;
}


// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Explanation: Use a dummy head for the sorted part. For each node in the original list, iterate through the sorted part to find its correct position and insert it.

ListNode* insertionSortList(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = head;
    while(curr) {
        ListNode* prev = dummy;
        while(prev->next && prev->next->val <= curr->val) {
            prev = prev->next;
        }
        ListNode* next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
    }
    return dummy->next;
}


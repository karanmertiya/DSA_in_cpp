// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use two pointers. Move `fast` pointer `k-1` steps. `first_node` is at `fast`. Initialize `slow = head`. Move both `slow` and `fast` to the end. `slow` will be at `second_node`. Swap values.

ListNode* swapNodes(ListNode* head, int k) {
    ListNode* fast = head;
    for(int i=1; i<k; i++) fast = fast->next;
    ListNode* firstNode = fast;
    ListNode* slow = head;
    while(fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    swap(firstNode->val, slow->val);
    return head;
}


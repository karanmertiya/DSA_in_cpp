// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Two-pointer approach. Move `fast` pointer `n` steps ahead. Then move both `slow` and `fast` until `fast` reaches the end. `slow` will be right before the target node.

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;
    for(int i = 0; i < n; i++) fast = fast->next;
    if(!fast) return head->next;
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}


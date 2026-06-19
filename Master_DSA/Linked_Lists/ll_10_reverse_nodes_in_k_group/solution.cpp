// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Iterative approach. Calculate the length. Use a dummy node. Maintain `pre`, `curr`, and `nex` pointers. Reverse `k-1` links in each group. Decrement length by `k` until length < `k`.

ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || k==1) return head;
    int length = 0;
    ListNode* temp = head;
    while(temp) { length++; temp = temp->next; }
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy, *curr = dummy, *nex = dummy;
    while(length >= k) {
        curr = pre->next;
        nex = curr->next;
        for(int i=1; i<k; i++) {
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        pre = curr; length -= k;
    }
    return dummy->next;
}


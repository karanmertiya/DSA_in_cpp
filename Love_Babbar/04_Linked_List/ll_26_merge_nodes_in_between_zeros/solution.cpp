// Time Complexity: O(N)
// Space Complexity: O(1) extra space if we modify in-place
// Explanation: Maintain a dummy node. Traverse the list. Maintain a running sum. When we encounter a 0 (and sum > 0), create a new node with `sum`, attach it to dummy list, reset `sum` to 0.

ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* currDummy = dummy;
    ListNode* curr = head->next;
    int sum = 0;
    while(curr) {
        if(curr->val == 0) {
            currDummy->next = new ListNode(sum);
            currDummy = currDummy->next;
            sum = 0;
        } else {
            sum += curr->val;
        }
        curr = curr->next;
    }
    return dummy->next;
}


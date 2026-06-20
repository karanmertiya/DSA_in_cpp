// Time Complexity: O(max(N, M))
// Space Complexity: O(max(N, M))
// Explanation: Iterate through both lists, keeping a `carry`. Create new nodes for the `sum % 10`.

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* temp = dummy;
    int carry = 0;
    while(l1 || l2 || carry) {
        int sum = carry;
        if(l1) { sum += l1->val; l1 = l1->next; }
        if(l2) { sum += l2->val; l2 = l2->next; }
        carry = sum / 10;
        temp->next = new ListNode(sum % 10);
        temp = temp->next;
    }
    return dummy->next;
}


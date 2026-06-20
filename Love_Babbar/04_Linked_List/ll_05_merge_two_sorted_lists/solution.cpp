// Time Complexity: O(N + M) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Use a dummy node to easily handle the head of the new list. Compare `list1` and `list2`, attaching the smaller node to `tail`.

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    while(list1 && list2) {
        if(list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = list1 ? list1 : list2;
    ListNode* res = dummy->next;
    delete dummy;
    return res;
}


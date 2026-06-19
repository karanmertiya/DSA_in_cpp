// Time Complexity: O(N log N)
// Space Complexity: O(log N)
// Explanation: Merge Sort. Use fast/slow pointers to find the middle of the linked list. Split into two halves, recursively sort both halves, then merge the two sorted halves.

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while(list1 && list2) {
        if(list1->val < list2->val) { tail->next = list1; list1 = list1->next; }
        else { tail->next = list2; list2 = list2->next; }
        tail = tail->next;
    }
    tail->next = list1 ? list1 : list2;
    return dummy.next;
}
ListNode* sortList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode *slow = head, *fast = head->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = NULL;
    return mergeTwoLists(sortList(head), sortList(mid));
}


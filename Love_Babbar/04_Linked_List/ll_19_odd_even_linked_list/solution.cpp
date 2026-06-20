// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Maintain two pointers `odd` and `even`. Keep the `evenHead`. Loop to link `odd->next = even->next` and `even->next = odd->next`. Finally, link `odd->next = evenHead`.

ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode *odd = head, *even = head->next, *evenHead = even;
    while(even && even->next) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}


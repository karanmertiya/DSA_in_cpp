// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Traverse the list while tracking the expected group length. First, count the actual number of nodes left in the current group. If the count is even, reverse this sublist and connect it to the previous part. If odd, just skip. Update lengths and pointers.

ListNode* reverseEvenLengthGroups(ListNode* head) {
    int groupLen = 1;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr != nullptr) {
        ListNode* temp = curr;
        int count = 0;
        while(count < groupLen && temp != nullptr) {
            temp = temp->next;
            count++;
        }
        if(count % 2 == 0) {
            ListNode* groupPrev = nullptr;
            ListNode* groupCurr = curr;
            ListNode* nextNode = nullptr;
            for(int i=0; i<count; i++) {
                nextNode = groupCurr->next;
                groupCurr->next = groupPrev;
                groupPrev = groupCurr;
                groupCurr = nextNode;
            }
            prev->next = groupPrev;
            curr->next = groupCurr;
            prev = curr;
            curr = groupCurr;
        } else {
            for(int i=0; i<count; i++) {
                prev = curr;
                curr = curr->next;
            }
        }
        groupLen++;
    }
    return head;
}


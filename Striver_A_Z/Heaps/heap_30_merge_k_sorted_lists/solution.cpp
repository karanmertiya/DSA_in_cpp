// Time Complexity: O(N log K)
// Space Complexity: O(K)
// Explanation: Push the head of each list into a min-heap. Extract the minimum node, append it to the merged list, and push its next node (if any) into the min-heap. Repeat until heap is empty.

struct comp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, comp> pq;
    for(ListNode* node : lists) {
        if(node) pq.push(node);
    }
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while(!pq.empty()) {
        ListNode* curr = pq.top();
        pq.pop();
        tail->next = curr;
        tail = tail->next;
        if(curr->next) pq.push(curr->next);
    }
    return dummy.next;
}


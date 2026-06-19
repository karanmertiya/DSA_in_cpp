// Time Complexity: O(N log K)
// Space Complexity: O(K)
// Explanation: Push the heads of all K lists into a Min-Heap. Pop the smallest node, append it to result, and if it has a next node, push the next node into the heap.

struct comp { bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; } };
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, comp> pq;
    for(auto head : lists) if(head) pq.push(head);
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    while(!pq.empty()) {
        ListNode* curr = pq.top(); pq.pop();
        tail->next = curr;
        tail = tail->next;
        if(curr->next) pq.push(curr->next);
    }
    return dummy->next;
}


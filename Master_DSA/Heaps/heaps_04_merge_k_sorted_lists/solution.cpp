// Time Complexity: O(N log K)
// Space Complexity: O(K)
// Explanation: Use a Min-Heap. Push the head of each linked list into the Priority Queue. Continuously pop the smallest, append it to result, and push its `next` node into the PQ.

struct compare {
    bool operator()(const ListNode* l, const ListNode* r) { return l->val > r->val; }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for(auto l : lists) if(l) pq.push(l);
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    while(!pq.empty()) {
        tail->next = pq.top(); pq.pop();
        tail = tail->next;
        if(tail->next) pq.push(tail->next);
    }
    return dummy->next;
}


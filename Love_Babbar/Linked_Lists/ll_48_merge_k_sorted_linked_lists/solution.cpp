// Time Complexity: O(N * K * log K)
// Space Complexity: O(K)
// Explanation: Create a min-heap and push the head of each linked list into it. Pop the minimum element, append it to the result list, and if the popped node has a next node, push the next node into the heap. Continue until the heap is empty.

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};
Node * mergeKLists(Node *arr[], int K) {
    priority_queue<Node*, vector<Node*>, compare> pq;
    for(int i = 0; i < K; i++) {
        if(arr[i]) pq.push(arr[i]);
    }
    Node* dummy = new Node(0);
    Node* tail = dummy;
    while(!pq.empty()) {
        Node* curr = pq.top();
        pq.pop();
        tail->next = curr;
        tail = tail->next;
        if(curr->next) pq.push(curr->next);
    }
    return dummy->next;
}


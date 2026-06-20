// Time Complexity: O(N log K)
// Space Complexity: O(K)
// Explanation: Create a Min Heap of size k+1. Insert the first k+1 elements into the heap. Then, pop the minimum element, place it in the sorted list, and push the next element from the original list into the heap.

struct compare {
    bool operator()(Node* p1, Node* p2) {
        return p1->data > p2->data;
    }
};
Node* sortAKSortedDLL(Node* head, int k) {
    if(head == NULL) return head;
    priority_queue<Node*, vector<Node*>, compare> pq;
    Node* newHead = NULL, *last = NULL;
    for(int i = 0; head != NULL && i <= k; i++) {
        pq.push(head);
        head = head->next;
    }
    while(!pq.empty()) {
        if(newHead == NULL) {
            newHead = pq.top();
            newHead->prev = NULL;
            last = newHead;
        } else {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
        pq.pop();
        if(head != NULL) {
            pq.push(head);
            head = head->next;
        }
    }
    last->next = NULL;
    return newHead;
}


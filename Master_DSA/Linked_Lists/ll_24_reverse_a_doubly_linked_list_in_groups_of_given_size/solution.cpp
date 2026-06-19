// Time Complexity: O(N)
// Space Complexity: O(N/K) recursion stack
// Explanation: Similar to reversing singly linked list in groups of k. Keep track of prev, next, and current. Reverse k nodes, then recursively call for the rest of the list.

Node* revListInGroupOfGivenSize(Node* head, int k) {
    if(!head) return NULL;
    Node *current = head, *next = NULL, *newHead = NULL;
    int count = 0;
    while(current != NULL && count < k) {
        next = current->next;
        current->prev = next;
        current->next = newHead;
        if(newHead != NULL) newHead->prev = current;
        newHead = current;
        current = next;
        count++;
    }
    if(next != NULL) {
        head->next = revListInGroupOfGivenSize(next, k);
        head->next->prev = head;
    }
    return newHead;
}


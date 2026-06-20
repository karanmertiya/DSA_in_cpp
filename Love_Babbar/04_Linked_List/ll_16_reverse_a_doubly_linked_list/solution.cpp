// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Traverse the DLL. For each node, swap its `prev` and `next` pointers. The new head will be the last node processed.

Node* reverseDLL(Node * head) {
    if(head == NULL || head->next == NULL) return head;
    Node* curr = head;
    Node* temp = NULL;
    while(curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    return temp->prev;
}


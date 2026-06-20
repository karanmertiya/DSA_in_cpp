// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Traverse the list. If `node->data == x`, update the `next` pointer of `node->prev` and `prev` pointer of `node->next`. If the node is head, update head.

void deleteAllOccurOfX(struct Node** head_ref, int x) {
    Node* curr = *head_ref;
    while(curr != NULL) {
        if(curr->data == x) {
            if(curr == *head_ref) *head_ref = curr->next;
            if(curr->prev != NULL) curr->prev->next = curr->next;
            if(curr->next != NULL) curr->next->prev = curr->prev;
            Node* toDelete = curr;
            curr = curr->next;
            free(toDelete);
        } else {
            curr = curr->next;
        }
    }
}


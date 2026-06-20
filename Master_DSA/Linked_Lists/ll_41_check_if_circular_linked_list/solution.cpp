// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Traverse the linked list starting from head. If we reach NULL, it's not circular. If we reach head again, it is circular.

bool isCircular(Node *head) {
    if(!head) return true;
    Node *temp = head->next;
    while(temp != NULL && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}


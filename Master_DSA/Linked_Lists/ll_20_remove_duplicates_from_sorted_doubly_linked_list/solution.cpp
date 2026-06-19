// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Traverse the DLL. While `next` node has the same value, bypass it by updating `curr->next` and `curr->next->prev`.

Node * removeDuplicates(struct Node *head) {
    Node* curr = head;
    while(curr != NULL) {
        Node* nextNode = curr->next;
        while(nextNode != NULL && nextNode->data == curr->data) {
            nextNode = nextNode->next;
        }
        curr->next = nextNode;
        if(nextNode != NULL) nextNode->prev = curr;
        curr = curr->next;
    }
    return head;
}


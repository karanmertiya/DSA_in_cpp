// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Traverse to the Nth node. This will be the new tail. Its next will be the new head. Traverse to the end of the list and link it to the original head.

Node *rotateDLL(Node *start, int N) {
    if (N == 0) return start;
    Node* current = start;
    int count = 1;
    while(count < N && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL) return start;
    Node* nthNode = current;
    while (current->next != NULL) current = current->next;
    current->next = start;
    start->prev = current;
    start = nthNode->next;
    start->prev = NULL;
    nthNode->next = NULL;
    return start;
}


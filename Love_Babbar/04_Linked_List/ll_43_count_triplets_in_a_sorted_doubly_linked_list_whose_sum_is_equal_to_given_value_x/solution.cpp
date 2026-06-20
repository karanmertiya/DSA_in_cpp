// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Explanation: Iterate through the list. For each node, use two pointers (left and right) on the remaining list to find pairs that sum to `x - node.data`.

int countTriplets(Node* head, int x) {
    if(!head) return 0;
    Node* curr, *first, *last;
    int count = 0;
    last = head;
    while(last->next != NULL) last = last->next;
    for(curr = head; curr != NULL; curr = curr->next) {
        first = curr->next;
        Node* right = last;
        while(first != NULL && right != NULL && first != right && right->next != first) {
            if((curr->data + first->data + right->data) == x) {
                count++;
                first = first->next;
                right = right->prev;
            } else if((curr->data + first->data + right->data) < x) {
                first = first->next;
            } else {
                right = right->prev;
            }
        }
    }
    return count;
}


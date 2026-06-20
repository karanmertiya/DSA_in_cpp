// Time Complexity: O(max(N, M))
// Space Complexity: O(max(N, M))
// Explanation: Reverse both linked lists. Traverse both lists simultaneously, adding the data values of corresponding nodes along with the carry. Create new nodes for the sum and append them to the result list. Finally, reverse the result list.

struct Node* reverse(struct Node* head) {
    Node* prev = NULL, *curr = head, *next = NULL;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
struct Node* addTwoLists(struct Node* first, struct Node* second) {
    first = reverse(first);
    second = reverse(second);
    Node* dummy = new Node(0), *temp = dummy;
    int carry = 0;
    while(first || second || carry) {
        int sum = carry;
        if(first) { sum += first->data; first = first->next; }
        if(second) { sum += second->data; second = second->next; }
        carry = sum / 10;
        temp->next = new Node(sum % 10);
        temp = temp->next;
    }
    return reverse(dummy->next);
}


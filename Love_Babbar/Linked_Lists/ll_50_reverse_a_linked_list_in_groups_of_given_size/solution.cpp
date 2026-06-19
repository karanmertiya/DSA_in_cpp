// Time Complexity: O(N)
// Space Complexity: O(N/K)
// Explanation: Reverse the first `k` nodes of the linked list iteratively. After reversing, the `head` pointer will be the end of the reversed group, and `curr` will point to the next node. Recursively call the function for `curr` and set `head->next` to the result.

struct node *reverse (struct node *head, int k) {
    if(!head) return NULL;
    struct node* curr = head, *prev = NULL, *next = NULL;
    int count = 0;
    while(curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next) head->next = reverse(next, k);
    return prev;
}


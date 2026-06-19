// Time Complexity: O(N)
// Space Complexity: O(N/k) recursive stack
// Explanation: Reverse the first k nodes iteratively. The next node becomes the head of the remaining list. Recursively call the function for the rest of the list and attach it to the tail of the reversed group (which is `head`). Return the new head.

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


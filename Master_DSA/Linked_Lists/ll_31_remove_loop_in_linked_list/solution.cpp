// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use Floyd's Cycle Detection. If a loop is found, reset `slow` to head. Move both `slow` and `fast` by 1. The node where they meet is the start of the loop. Keep track of `fast`'s previous node to set its `next` to NULL.

void removeLoop(Node* head) {
    if(!head || !head->next) return;
    Node* slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(slow == fast) {
        slow = head;
        if(slow == fast) {
            while(fast->next != slow) fast = fast->next;
        } else {
            while(slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }
}


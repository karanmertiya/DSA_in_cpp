// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use Floyd's cycle finding algorithm. Once `slow` and `fast` meet, move `slow` to the `head`. Then move both `slow` and `fast` by 1 step. They will meet at the starting node of the loop.

int findFirstNode(Node* head) {
    if(!head) return -1;
    Node* slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(slow != fast) return -1;
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}


// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Create two dummy nodes, one for the even list and one for the odd list. Traverse the original list and append even nodes to the even list and odd nodes to the odd list. Finally, connect the end of the even list to the head of the odd list and terminate the odd list with NULL.

Node* divide(int N, Node *head) {
    Node* evenStart = NULL, *evenEnd = NULL;
    Node* oddStart = NULL, *oddEnd = NULL;
    Node* curr = head;
    while(curr) {
        int val = curr->data;
        if(val % 2 == 0) {
            if(!evenStart) { evenStart = curr; evenEnd = evenStart; }
            else { evenEnd->next = curr; evenEnd = evenEnd->next; }
        } else {
            if(!oddStart) { oddStart = curr; oddEnd = oddStart; }
            else { oddEnd->next = curr; oddEnd = oddEnd->next; }
        }
        curr = curr->next;
    }
    if(!oddStart || !evenStart) return head;
    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    return evenStart;
}


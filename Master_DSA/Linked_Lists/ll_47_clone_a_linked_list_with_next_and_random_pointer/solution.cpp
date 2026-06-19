// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Create a copy of each node and insert it immediately after the original node. Then, set the random pointers for the copied nodes (`curr->next->arb = curr->arb ? curr->arb->next : NULL`). Finally, separate the original and copied lists.

Node *copyList(Node *head) {
    if(!head) return NULL;
    Node* curr = head;
    while(curr) {
        Node* temp = new Node(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        curr = temp->next;
    }
    curr = head;
    while(curr) {
        if(curr->arb) curr->next->arb = curr->arb->next;
        curr = curr->next->next;
    }
    curr = head;
    Node* copyHead = head->next, *copyCurr = copyHead;
    while(curr) {
        curr->next = curr->next->next;
        if(copyCurr->next) copyCurr->next = copyCurr->next->next;
        curr = curr->next;
        copyCurr = copyCurr->next;
    }
    return copyHead;
}


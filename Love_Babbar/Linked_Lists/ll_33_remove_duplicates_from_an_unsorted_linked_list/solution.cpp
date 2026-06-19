// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a hash set to store the seen values. Iterate the list. If a node's value is in the set, skip it by updating the `next` pointer of the `prev` node. Else, add it to the set and update `prev`.

Node * removeDuplicates(Node *head) {
    if(!head) return NULL;
    unordered_set<int> seen;
    Node* curr = head, *prev = NULL;
    while(curr) {
        if(seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}


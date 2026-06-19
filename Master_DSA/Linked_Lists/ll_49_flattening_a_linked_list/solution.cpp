// Time Complexity: O(N * M)
// Space Complexity: O(N) for recursion
// Explanation: Recursively flatten the `next` list, then merge the current list (`bottom`) with the flattened `next` list using a `merge` function similar to merging two sorted linked lists.

Node* merge(Node* a, Node* b) {
    if(!a) return b;
    if(!b) return a;
    Node* res;
    if(a->data < b->data) {
        res = a;
        res->bottom = merge(a->bottom, b);
    } else {
        res = b;
        res->bottom = merge(a, b->bottom);
    }
    res->next = NULL;
    return res;
}
Node *flatten(Node *root) {
    if(!root || !root->next) return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}


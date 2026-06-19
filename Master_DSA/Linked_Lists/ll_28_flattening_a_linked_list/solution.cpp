// Time Complexity: O(N * M) total nodes
// Space Complexity: O(N) aux space for recursion
// Explanation: Recursively go to the end of the `next` pointers. Merge the last two lists using the `bottom` pointers, just like merging two sorted linked lists. Return the merged head upwards.

struct Node {
    int data;
    Node *next, *bottom;
    Node(int x) { data = x; next = NULL; bottom = NULL; }
};
Node* mergeTwoLists(Node* a, Node* b) {
    Node* temp = new Node(0);
    Node* res = temp;
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        } else {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if(a) temp->bottom = a;
    else temp->bottom = b;
    return res->bottom;
}
Node *flatten(Node *root) {
    if(root == NULL || root->next == NULL) return root;
    root->next = flatten(root->next);
    root = mergeTwoLists(root, root->next);
    return root;
}


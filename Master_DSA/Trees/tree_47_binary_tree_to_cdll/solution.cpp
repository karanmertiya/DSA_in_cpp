// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Perform an inorder traversal. Maintain a `prev` pointer. If `prev` is NULL, it's the `head`. Else, set `prev->right = curr` and `curr->left = prev`. Update `prev = curr`. Finally, connect `head` and `prev` (the tail).

void inorder(Node* root, Node*& prev, Node*& head) {
    if(!root) return;
    inorder(root->left, prev, head);
    if(!head) head = root;
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    inorder(root->right, prev, head);
}
Node* bTreeToCList(Node* root) {
    Node* head = NULL;
    Node* prev = NULL;
    inorder(root, prev, head);
    if(head && prev) {
        head->left = prev;
        prev->right = head;
    }
    return head;
}


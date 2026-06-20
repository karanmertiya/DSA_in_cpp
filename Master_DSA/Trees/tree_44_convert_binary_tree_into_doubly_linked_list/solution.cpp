// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Perform Inorder traversal. Maintain a `prev` pointer (initially null). At each node: if `prev == null`, this node is the head of DLL. Else, `prev->right = node` and `node->left = prev`. Update `prev = node`.

void bToDLLHelper(Node* root, Node*& head, Node*& prev) {
    if(!root) return;
    bToDLLHelper(root->left, head, prev);
    if(prev == NULL) {
        head = root;
    } else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    bToDLLHelper(root->right, head, prev);
}
Node *bToDLL(Node *root) {
    Node* head = NULL;
    Node* prev = NULL;
    bToDLLHelper(root, head, prev);
    return head;
}


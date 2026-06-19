// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Use a postorder traversal. For a node, store its original value. Update the node's value to the sum of its left and right subtrees. Return the old value plus the new value to the parent.

int toSumTreeUtil(Node* root) {
    if(!root) return 0;
    int old_val = root->data;
    root->data = toSumTreeUtil(root->left) + toSumTreeUtil(root->right);
    return root->data + old_val;
}
void toSumTree(Node *node) {
    toSumTreeUtil(node);
}


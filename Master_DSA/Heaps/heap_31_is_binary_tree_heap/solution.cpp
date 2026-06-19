// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: First, check if the tree is complete by counting nodes and ensuring no node's index `i > count`. Then check if every node satisfies the max-heap property (`node.val >= left.val` and `node.val >= right.val`).

int countNodes(Node* root) {
    if(!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isCBT(Node* root, int index, int count) {
    if(!root) return true;
    if(index >= count) return false;
    return isCBT(root->left, 2 * index + 1, count) && isCBT(root->right, 2 * index + 2, count);
}
bool isMaxOrder(Node* root) {
    if(!root->left && !root->right) return true;
    if(!root->right) return root->data >= root->left->data;
    return (root->data >= root->left->data) && (root->data >= root->right->data) && isMaxOrder(root->left) && isMaxOrder(root->right);
}
bool isHeap(struct Node* tree) {
    int count = countNodes(tree);
    return isCBT(tree, 0, count) && isMaxOrder(tree);
}


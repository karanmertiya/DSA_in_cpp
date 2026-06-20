// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Return `[minNode, maxNode, maxSize]` from each subtree. For current node, if `left.max < node.val < right.min`, it's a BST. Return `[min(node.val, left.min), max(node.val, right.max), left.size + right.size + 1]`. Else, it's not a BST, return `[-inf, inf, max(left.size, right.size)]`.

class NodeValue {
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
NodeValue largestBSTSubtreeHelper(Node* root) {
    if(!root) return NodeValue(INT_MAX, INT_MIN, 0);
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);
    if(left.maxNode < root->data && root->data < right.minNode) {
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
int largestBst(Node *root) {
    return largestBSTSubtreeHelper(root).maxSize;
}


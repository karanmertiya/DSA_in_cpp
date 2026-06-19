// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Return a struct `[minNode, maxNode, maxSize]`. For any node, if `left.maxNode < node.val < right.minNode`, it's a BST. Then `size = left.maxSize + right.maxSize + 1`. Return `[min(left.min, node.val), max(right.max, node.val), size]`. If not a BST, return `[-inf, inf, max(left.size, right.size)]`.

class NodeValue {
public:
    int minNode, maxNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};
NodeValue largestBSTSubtreeHelper(TreeNode* root) {
    if(!root) return NodeValue(INT_MAX, INT_MIN, 0);
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);
    if(left.maxNode < root->val && root->val < right.minNode) {
        return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
    }
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
int largestBst(TreeNode *root) {
    return largestBSTSubtreeHelper(root).maxSize;
}


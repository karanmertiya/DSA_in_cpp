// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Modify the Height algorithm. If the difference between `left` and `right` height is > 1, return `-1` to propagate the unbalanced signal.

int checkHeight(TreeNode* node) {
    if(!node) return 0;
    int left = checkHeight(node->left);
    if(left == -1) return -1;
    int right = checkHeight(node->right);
    if(right == -1) return -1;
    if(std::abs(left - right) > 1) return -1;
    return 1 + std::max(left, right);
}
bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}


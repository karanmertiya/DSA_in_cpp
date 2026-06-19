// Time Complexity: O(N)
// Space Complexity: O(N) recursion stack
// Explanation: Modify the `maxDepth` function to return -1 if the tree is not balanced. If `abs(left - right) > 1` or either subtree returns -1, return -1. Otherwise, return `max(left, right) + 1`.

int checkHeight(TreeNode* root) {
    if(root == NULL) return 0;
    int leftHeight = checkHeight(root->left);
    if(leftHeight == -1) return -1;
    int rightHeight = checkHeight(root->right);
    if(rightHeight == -1) return -1;
    if(abs(leftHeight - rightHeight) > 1) return -1;
    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}


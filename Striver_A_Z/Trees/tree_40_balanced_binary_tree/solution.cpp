// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Modify the function that calculates the height of the tree. If at any node, the difference between the left and right subtree heights is greater than 1, or if any subtree is unbalanced, return -1. Otherwise, return the height.

int checkHeight(TreeNode* root) {
    if(!root) return 0;
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


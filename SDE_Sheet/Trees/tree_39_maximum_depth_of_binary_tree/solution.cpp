// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Recursively find the maximum depth of the left subtree and the right subtree. The maximum depth of the tree is `1 + max(left_depth, right_depth)`.

int maxDepth(TreeNode* root) {
    if(!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


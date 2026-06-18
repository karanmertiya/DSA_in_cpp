// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: If we find `p` or `q`, return it. If both left and right return non-null, current node is LCA.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (!left) return right;
    else if (!right) return left;
    else return root;
}


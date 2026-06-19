// Time Complexity: O(N)
// Space Complexity: O(H) recursion stack
// Explanation: DFS traversal. If root is NULL or equals p or q, return root. Recursively find LCA in left and right subtrees. If both return non-null, root is LCA. Otherwise return the non-null child.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;
    return left ? left : right;
}


// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: DFS traversal. If the current node is p or q, return the current node. Recurse left and right. If both left and right return non-null, the current node is the LCA. If one returns non-null, return that one.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return root;
}


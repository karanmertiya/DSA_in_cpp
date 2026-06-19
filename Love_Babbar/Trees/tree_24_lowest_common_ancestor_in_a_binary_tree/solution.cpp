// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: If root is null or root matches n1 or n2, return root. Recurse for left and right. If both return non-null, root is LCA. If one returns non-null, return that one.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return root;
}


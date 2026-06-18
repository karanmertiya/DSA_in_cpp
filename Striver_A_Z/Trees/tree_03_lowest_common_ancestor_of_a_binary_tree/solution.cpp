// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N)
// Explanation: Traverse the tree. If we find `p` or `q`, return it. If left and right subtrees both return non-null, the current node is the LCA. Otherwise, return the non-null subtree result.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left == nullptr) return right;
    else if (right == nullptr) return left;
    else return root; // Both left and right are not null
}


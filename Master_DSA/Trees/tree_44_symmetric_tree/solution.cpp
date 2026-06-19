// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Use a helper function `isMirror(left, right)`. The tree is symmetric if `root->left` and `root->right` are mirrors. Two trees are mirrors if their roots are equal and `left1->left` is mirror of `right1->right`, and `left1->right` is mirror of `right1->left`.

bool isMirror(TreeNode* n1, TreeNode* n2) {
    if(!n1 && !n2) return true;
    if(!n1 || !n2) return false;
    return (n1->val == n2->val) && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
}
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    return isMirror(root->left, root->right);
}


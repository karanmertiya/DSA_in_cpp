// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Pass a valid range `(min_val, max_val)` for each node. For the root, it's `(-infinity, infinity)`. If node value is outside range, return false. Recursively check left subtree with range `(min_val, node.val)` and right subtree with `(node.val, max_val)`.

bool isValidBST(TreeNode* root, long minVal, long maxVal) {
    if(root == NULL) return true;
    if(root->val >= maxVal || root->val <= minVal) return false;
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}
bool isValidBST(TreeNode* root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
}


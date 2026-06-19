// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Recursive validation with min and max bounds. `isValidBST(root, min_val, max_val)`. Ensure `min_val < root.val < max_val`. For left child update `max_val = root.val`. For right child update `min_val = root.val`.

bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal) {
    if(!root) return true;
    if(root->val <= minVal || root->val >= maxVal) return false;
    return isValidBSTHelper(root->left, minVal, root->val) && isValidBSTHelper(root->right, root->val, maxVal);
}
bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}


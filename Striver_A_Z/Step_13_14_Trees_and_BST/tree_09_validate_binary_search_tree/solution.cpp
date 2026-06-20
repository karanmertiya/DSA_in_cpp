// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Recursive validation with min and max bounds for every node. Long long is used to avoid overflow.

bool isValidBST(TreeNode* root, long minVal, long maxVal) {
    if(!root) return true;
    if(root->val >= maxVal || root->val <= minVal) return false;
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}
bool isValidBST(TreeNode* root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
}


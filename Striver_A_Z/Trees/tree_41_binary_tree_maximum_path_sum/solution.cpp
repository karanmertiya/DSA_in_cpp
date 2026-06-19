// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Use a recursive postorder function. For each node, calculate the maximum path sum in its left and right subtrees (ignoring negative sums by taking max(0, sum)). Update the global `max_sum` with `node.val + left_sum + right_sum`. Return `node.val + max(left_sum, right_sum)` to be used by the parent.

int maxPathDown(TreeNode* root, int& maxi) {
    if(!root) return 0;
    int left = max(0, maxPathDown(root->left, maxi));
    int right = max(0, maxPathDown(root->right, maxi));
    maxi = max(maxi, root->val + left + right);
    return root->val + max(left, right);
}
int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}


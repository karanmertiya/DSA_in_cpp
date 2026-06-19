// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: DFS returning max path sum down a single branch. At any node, max path = `node.val + max(0, leftPath) + max(0, rightPath)`. Ignore negative branches.

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}
int maxPathDown(TreeNode* node, int& maxi) {
    if(!node) return 0;
    int left = max(0, maxPathDown(node->left, maxi));
    int right = max(0, maxPathDown(node->right, maxi));
    maxi = max(maxi, left + right + node->val);
    return max(left, right) + node->val;
}


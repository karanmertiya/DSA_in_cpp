// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Bottom-up traversal. Return `[isBST, minNode, maxNode, sum]`. Update global max sum when valid BST is found.

struct Info {
    bool isBST;
    int minNode, maxNode, sum;
};
int maxSum = 0;
Info solve(TreeNode* root) {
    if(!root) return {true, INT_MAX, INT_MIN, 0};
    Info left = solve(root->left);
    Info right = solve(root->right);
    if(left.isBST && right.isBST && left.maxNode < root->val && root->val < right.minNode) {
        int currSum = left.sum + right.sum + root->val;
        maxSum = max(maxSum, currSum);
        return {true, min(root->val, left.minNode), max(root->val, right.maxNode), currSum};
    }
    return {false, INT_MIN, INT_MAX, max(left.sum, right.sum)};
}
int maxSumBST(TreeNode* root) {
    maxSum = 0;
    solve(root);
    return maxSum > 0 ? maxSum : 0;
}


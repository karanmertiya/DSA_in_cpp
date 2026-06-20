// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Recursively get the sum of the left subtree and right subtree. Update current node's value to the sum of left and right. Return the old value of current node + sum of left + sum of right to the caller.

int toSumTree(TreeNode* root) {
    if(!root) return 0;
    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);
    int oldVal = root->val;
    root->val = leftSum + rightSum;
    return root->val + oldVal;
}


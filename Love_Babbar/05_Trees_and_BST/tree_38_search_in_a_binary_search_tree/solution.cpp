// Time Complexity: O(H)
// Space Complexity: O(1)
// Explanation: Start at root. If root is null or its value is `val`, return root. If `val < root.val`, go left. Else go right.

TreeNode* searchBST(TreeNode* root, int val) {
    while(root != NULL && root->val != val) {
        root = val < root->val ? root->left : root->right;
    }
    return root;
}


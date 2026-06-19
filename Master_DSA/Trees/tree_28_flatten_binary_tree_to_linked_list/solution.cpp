// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Morris Traversal. If node has a left child, find the rightmost node of the left subtree. Point its right to current node's right. Move current node's left to its right, and set left to null. Move to current's right.

void flatten(TreeNode* root) {
    TreeNode* curr = root;
    while(curr) {
        if(curr->left) {
            TreeNode* pre = curr->left;
            while(pre->right) pre = pre->right;
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}


// Time Complexity: O(N)
// Space Complexity: O(1) using Morris Traversal
// Explanation: Inorder traversal of BST gives sorted elements. Keep a counter, when it reaches K, store the result. Morris Traversal can do this in O(1) space.

int kthSmallest(TreeNode* root, int k) {
    int count = 0, ans = -1;
    TreeNode* curr = root;
    while(curr) {
        if(curr->left == NULL) {
            count++;
            if(count == k) ans = curr->val;
            curr = curr->right;
        } else {
            TreeNode* pre = curr->left;
            while(pre->right && pre->right != curr) pre = pre->right;
            if(pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = NULL;
                count++;
                if(count == k) ans = curr->val;
                curr = curr->right;
            }
        }
    }
    return ans;
}


// Time Complexity: O(K) or O(N)
// Space Complexity: O(H) or O(1)
// Explanation: Perform an inorder traversal (Recursive or Iterative/Morris) and keep track of count. When count reaches `k`, return the node's value.

int kthSmallest(TreeNode* root, int k) {
    int count = 0, ans = -1;
    TreeNode* curr = root;
    while(curr != NULL) {
        if(curr->left == NULL) {
            count++;
            if(count == k) ans = curr->val;
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;
            while(prev->right && prev->right != curr) prev = prev->right;
            if(prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = NULL;
                count++;
                if(count == k) ans = curr->val;
                curr = curr->right;
            }
        }
    }
    return ans;
}


// Time Complexity: O(H)
// Space Complexity: O(1)
// Explanation: Traverse the tree. If `val < current.val`, go left. If left is null, insert here. If `val > current.val`, go right. If right is null, insert here.

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);
    TreeNode* curr = root;
    while(true) {
        if(curr->val <= val) {
            if(curr->right != NULL) curr = curr->right;
            else {
                curr->right = new TreeNode(val);
                break;
            }
        } else {
            if(curr->left != NULL) curr = curr->left;
            else {
                curr->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}


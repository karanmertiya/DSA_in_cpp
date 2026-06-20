// Time Complexity: O(H)
// Space Complexity: O(1)
// Explanation: Traverse left or right depending on the value. Keep track of parent. Insert as left or right child of parent when a null pointer is reached.

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    TreeNode* curr = root;
    while(true) {
        if(val < curr->val) {
            if(curr->left) curr = curr->left;
            else { curr->left = new TreeNode(val); break; }
        } else {
            if(curr->right) curr = curr->right;
            else { curr->right = new TreeNode(val); break; }
        }
    }
    return root;
}


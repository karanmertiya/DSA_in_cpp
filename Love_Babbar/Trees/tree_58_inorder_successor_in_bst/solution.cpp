// Time Complexity: O(H)
// Space Complexity: O(1)
// Explanation: Start from root. If `p.val >= root.val`, the successor must be in the right subtree (`root = root.right`). If `p.val < root.val`, the current root could be the successor, so record it and search the left subtree for a closer successor (`successor = root; root = root.left`).

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = NULL;
    while(root != NULL) {
        if(p->val >= root->val) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}


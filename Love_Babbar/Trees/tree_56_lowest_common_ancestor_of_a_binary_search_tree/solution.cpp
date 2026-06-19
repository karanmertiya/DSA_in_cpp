// Time Complexity: O(H)
// Space Complexity: O(1)
// Explanation: Start at root. If both `p` and `q` are less than root, move left. If both are greater, move right. Otherwise, the current node is the LCA.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while(root != NULL) {
        if(p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if(p->val > root->val && q->val > root->val) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}


// Time Complexity: O(H)
// Space Complexity: O(1)
// Explanation: If both `p` and `q` are less than root, LCA is in the left subtree. If both are greater, LCA is in the right subtree. Otherwise, the current node is the LCA.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while(root) {
        if(root->val > p->val && root->val > q->val) root = root->left;
        else if(root->val < p->val && root->val < q->val) root = root->right;
        else return root;
    }
    return NULL;
}


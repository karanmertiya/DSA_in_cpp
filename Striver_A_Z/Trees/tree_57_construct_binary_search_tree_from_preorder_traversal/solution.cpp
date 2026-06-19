// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Keep track of an index for the `preorder` array and a maximum valid bound. To build the left subtree, the upper bound is the current node's value. To build the right subtree, the bound remains the parent's bound. If the current value is greater than the bound, return NULL.

TreeNode* build(vector<int>& preorder, int& i, int bound) {
    if(i == preorder.size() || preorder[i] > bound) return NULL;
    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = build(preorder, i, root->val);
    root->right = build(preorder, i, bound);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return build(preorder, i, INT_MAX);
}


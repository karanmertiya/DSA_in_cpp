// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Recursively swap the left and right children of every node.

TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr;
    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}


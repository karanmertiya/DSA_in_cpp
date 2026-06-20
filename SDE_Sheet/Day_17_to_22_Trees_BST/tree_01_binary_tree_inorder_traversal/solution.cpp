// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Recursive approach. Traverse Left, process Root, then traverse Right.

void inorder(TreeNode* root, std::vector<int>& ans) {
    if (!root) return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> ans;
    inorder(root, ans);
    return ans;
}


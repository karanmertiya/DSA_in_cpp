// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: DFS Traversing right child before left child. Maintain the current level. If `level == result.size()`, append the node value to the result list.

void recursion(TreeNode *root, int level, vector<int> &res) {
    if(root==NULL) return ;
    if(res.size() == level) res.push_back(root->val);
    recursion(root->right, level + 1, res);
    recursion(root->left, level + 1, res);
}
vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    recursion(root, 0, res);
    return res;
}


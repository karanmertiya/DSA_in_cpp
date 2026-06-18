// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Modify the Height/Depth algorithm. Calculate `left_depth + right_depth` at every node to find max diameter, while returning standard height.

int height(TreeNode* node, int& max_d) {
    if(!node) return 0;
    int left = height(node->left, max_d);
    int right = height(node->right, max_d);
    max_d = std::max(max_d, left + right);
    return 1 + std::max(left, right);
}
int diameterOfBinaryTree(TreeNode* root) {
    int max_d = 0;
    height(root, max_d);
    return max_d;
}


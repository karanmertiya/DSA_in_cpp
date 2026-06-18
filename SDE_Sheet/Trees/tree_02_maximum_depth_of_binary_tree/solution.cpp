// Time Complexity: O(N) (Constraint)
// Space Complexity: O(H) &cong; O(N) (Constraint)
// Explanation: Recursively find the max depth of left and right subtrees. The depth of the current node is `1 + max(left_depth, right_depth)`.

#include <algorithm>

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + std::max(leftDepth, rightDepth);
}


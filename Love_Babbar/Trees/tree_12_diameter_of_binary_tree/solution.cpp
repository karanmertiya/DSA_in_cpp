// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Modify the standard Height of Binary Tree DFS. Compute left height and right height. At each node, the diameter passing through it is `left + right`. Track the max.

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
int height(TreeNode* node, int& diameter) {
    if(!node) return 0;
    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}


// Time Complexity: O(log^2 N)
// Space Complexity: O(log N)
// Explanation: Compute the left height (following left child) and right height (following right child) of the tree. If they are equal, the tree is a full binary tree, and the number of nodes is `2^h - 1`. If they are not equal, recursively count the nodes in the left and right subtrees and add 1 for the root.

int getLeftHeight(TreeNode* node) {
    int h = 0;
    while(node) {
        h++;
        node = node->left;
    }
    return h;
}
int getRightHeight(TreeNode* node) {
    int h = 0;
    while(node) {
        h++;
        node = node->right;
    }
    return h;
}
int countNodes(TreeNode* root) {
    if(!root) return 0;
    int lh = getLeftHeight(root);
    int rh = getRightHeight(root);
    if(lh == rh) return (1 << lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


// Time Complexity: O(H)
// Space Complexity: O(H) or O(1)
// Explanation: Find the node. If it has no left child, return right child. If no right, return left. If both exist, find the right child of the rightmost node in the left subtree, and point it to the node's right child. Return the node's left child.

TreeNode* helper(TreeNode* root) {
    if(!root->left) return root->right;
    if(!root->right) return root->left;
    TreeNode* rightChild = root->right;
    TreeNode* lastRight = root->left;
    while(lastRight->right) lastRight = lastRight->right;
    lastRight->right = rightChild;
    return root->left;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return NULL;
    if(root->val == key) return helper(root);
    TreeNode* curr = root;
    while(curr) {
        if(curr->val > key) {
            if(curr->left && curr->left->val == key) {
                curr->left = helper(curr->left);
                break;
            } else curr = curr->left;
        } else {
            if(curr->right && curr->right->val == key) {
                curr->right = helper(curr->right);
                break;
            } else curr = curr->right;
        }
    }
    return root;
}


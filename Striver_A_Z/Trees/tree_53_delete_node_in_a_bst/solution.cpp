// Time Complexity: O(H)
// Space Complexity: O(1)
// Explanation: Search for the node. If found, there are 3 cases: Node is a leaf (just remove), Node has 1 child (replace with child), Node has 2 children (find inorder successor, i.e., min in right subtree, copy value, delete successor from right subtree). Alternatively, connect the left subtree to the leftmost node of the right subtree.

TreeNode* helper(TreeNode* root) {
    if(root->left == NULL) return root->right;
    if(root->right == NULL) return root->left;
    TreeNode* rightChild = root->right;
    TreeNode* lastRight = root->left;
    while(lastRight->right != NULL) lastRight = lastRight->right;
    lastRight->right = rightChild;
    return root->left;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) return NULL;
    if(root->val == key) return helper(root);
    TreeNode* dummy = root;
    while(root != NULL) {
        if(root->val > key) {
            if(root->left != NULL && root->left->val == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if(root->right != NULL && root->right->val == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return dummy;
}


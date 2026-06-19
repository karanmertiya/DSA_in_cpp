// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Morris-like approach (O(1) space): If node has a left child, find the rightmost node in the left subtree. Connect it to the current node's right child. Move the left child to the right child, and set the left child to null. Move to the next right node.

void flatten(TreeNode* root) {
    TreeNode* curr = root;
    while(curr != NULL) {
        if(curr->left != NULL) {
            TreeNode* prev = curr->left;
            while(prev->right) {
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}


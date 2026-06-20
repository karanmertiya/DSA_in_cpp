// Time Complexity: O(H)
// Space Complexity: O(1)
// Explanation: Traverse the left children until a node with no left child is reached. That node contains the minimum value.

int minValue(TreeNode* root) {
    if(root == NULL) return -1;
    while(root->left != NULL) {
        root = root->left;
    }
    return root->val;
}


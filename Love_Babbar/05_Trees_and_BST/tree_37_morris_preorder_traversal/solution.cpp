// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Similar to Morris Inorder. If left child is null, process current, move right. Else, find predecessor. If predecessor's right is null, process current, make thread, move left. If predecessor's right is current, remove thread, move right.

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode* curr = root;
    while(curr != NULL) {
        if(curr->left == NULL) {
            preorder.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;
            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }
            if(prev->right == NULL) {
                prev->right = curr;
                preorder.push_back(curr->val);
                curr = curr->left;
            } else {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}


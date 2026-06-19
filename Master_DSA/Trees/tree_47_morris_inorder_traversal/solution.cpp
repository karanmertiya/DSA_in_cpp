// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: If left child is null, process current node, move to right. Else, find predecessor (rightmost node in left subtree). If predecessor's right is null, make it point to current (thread), move to left. If predecessor's right is current, remove thread, process current, move to right.

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode* curr = root;
    while(curr != NULL) {
        if(curr->left == NULL) {
            inorder.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;
            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }
            if(prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}


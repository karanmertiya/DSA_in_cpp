// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Inorder traversal of BST gives sorted array. If two are swapped, there will be 1 or 2 anomalies where `prev->val > curr->val`. First anomaly: `first = prev`, `middle = curr`. Second anomaly: `last = curr`. Swap `first` and `last` (or `first` and `middle` if adjacent).

TreeNode *first, *prev, *middle, *last;
void inorder(TreeNode* root) {
    if(root == NULL) return;
    inorder(root->left);
    if(prev != NULL && (root->val < prev->val)) {
        if(first == NULL) {
            first = prev;
            middle = root;
        } else {
            last = root;
        }
    }
    prev = root;
    inorder(root->right);
}
void recoverTree(TreeNode* root) {
    first = middle = last = NULL;
    prev = new TreeNode(INT_MIN);
    inorder(root);
    if(first && last) swap(first->val, last->val);
    else if(first && middle) swap(first->val, middle->val);
}


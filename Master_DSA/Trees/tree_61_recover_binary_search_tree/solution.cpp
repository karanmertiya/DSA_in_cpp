// Time Complexity: O(N)
// Space Complexity: O(H) or O(1) with Morris
// Explanation: Maintain `prev`, `first`, `middle`, and `last` pointers during inorder traversal. If `prev.val > root.val`, a violation occurred. The first violation points to `first=prev` and `middle=root`. A second violation (if any) points to `last=root`. Finally, swap values of `first` and `last` (or `first` and `middle` if adjacent).

TreeNode* first; TreeNode* prev; TreeNode* middle; TreeNode* last;
void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    if(prev && root->val < prev->val) {
        if(!first) {
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


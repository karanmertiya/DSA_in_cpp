// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Traverse both trees simultaneously. If both nodes are null, true. If one is null or values mismatch, false.

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if(!p || !q || p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


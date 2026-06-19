// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Preorder DFS simultaneously on both trees. If both are null, true. If one is null or vals mismatch, false. Recursively check left and right subtrees.

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p || !q) return p == q;
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Implement two BST iterators: one for normal inorder (next) and one for reverse inorder (before). Set `i = next()` and `j = before()`. While `i < j`, if `i + j == k` return true, if `i + j < k` increment `i`, else decrement `j`.

class BSTIterator {
    stack<TreeNode*> st;
    bool reverse = true;
    void pushAll(TreeNode* node) {
        while(node) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    int next() {
        TreeNode* tmp = st.top(); st.pop();
        pushAll(reverse ? tmp->left : tmp->right);
        return tmp->val;
    }
};
bool findTarget(TreeNode* root, int k) {
    if(!root) return false;
    BSTIterator l(root, false);
    BSTIterator r(root, true);
    int i = l.next();
    int j = r.next();
    while(i < j) {
        if(i + j == k) return true;
        else if(i + j < k) i = l.next();
        else j = r.next();
    }
    return false;
}


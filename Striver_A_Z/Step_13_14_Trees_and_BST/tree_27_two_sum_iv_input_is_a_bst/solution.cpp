// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Use two BST iterators: one for normal inorder (next) and one for reverse inorder (before). Apply two-pointer approach like in a sorted array.

class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;
    void pushAll(TreeNode* node) {
        while(node) {
            st.push(node);
            if(reverse) node = node->right;
            else node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    int next() {
        TreeNode* tmpNode = st.top();
        st.pop();
        if(reverse) pushAll(tmpNode->left);
        else pushAll(tmpNode->right);
        return tmpNode->val;
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


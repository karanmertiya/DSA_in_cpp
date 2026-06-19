// Time Complexity: O(1) average per call
// Space Complexity: O(H)
// Explanation: Maintain a stack of nodes. In constructor, push all left children of root. In `next()`, pop top, value is answer, if popped node has right child, push it and all its left children. `hasNext()` checks if stack is not empty.

class BSTIterator {
    stack<TreeNode*> st;
    void pushAll(TreeNode* node) {
        for(; node != NULL; st.push(node), node = node->left);
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    int next() {
        TreeNode* tmpNode = st.top();
        st.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
    bool hasNext() {
        return !st.empty();
    }
};


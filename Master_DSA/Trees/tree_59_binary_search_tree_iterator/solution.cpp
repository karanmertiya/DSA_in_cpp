// Time Complexity: O(1) amortized for next/hasNext
// Space Complexity: O(H)
// Explanation: Use a stack to simulate inorder traversal. In constructor, push all left children of root to stack. For `next()`, pop the top node, push all left children of its right child, and return the popped node's value. `hasNext()` checks if stack is not empty.

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


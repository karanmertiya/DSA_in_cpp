// Time Complexity: O(1) amortized
// Space Complexity: O(H)
// Explanation: Use a stack to simulate in-order traversal. Push all left children initially. On next(), pop, return val, and push all left children of popped node's right child.

class BSTIterator {
    stack<TreeNode*> st;
    void pushAll(TreeNode* node) {
        while(node) {
            st.push(node);
            node = node->left;
        }
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


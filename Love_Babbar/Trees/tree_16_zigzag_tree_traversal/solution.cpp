// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a queue for level order traversal. Maintain a `leftToRight` boolean flag. At each level, collect the nodes and reverse the list if `leftToRight` is false. Toggle the flag after each level.

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()) {
        int size = q.size();
        vector<int> row(size);
        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            int index = leftToRight ? i : (size - 1 - i);
            row[index] = node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        leftToRight = !leftToRight;
        res.push_back(row);
    }
    return res;
}


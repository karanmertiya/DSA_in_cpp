// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Standard BFS Level Order Traversal with a boolean flag `leftToRight`. After finishing a level, if the flag is false, reverse the level array before adding to the result.

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(!root) return result;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()) {
        int size = q.size();
        vector<int> row(size);
        for(int i=0; i<size; i++) {
            TreeNode* node = q.front(); q.pop();
            int index = leftToRight ? i : (size - 1 - i);
            row[index] = node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}


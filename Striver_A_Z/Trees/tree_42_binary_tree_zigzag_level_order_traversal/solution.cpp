// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Perform standard BFS using a queue. Maintain a boolean flag `leftToRight`. After processing a level, if `leftToRight` is false, reverse the current level's vector before adding it to the result. Toggle the flag for the next level.

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()) {
        int size = q.size();
        vector<int> level(size);
        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(level);
    }
    return ans;
}


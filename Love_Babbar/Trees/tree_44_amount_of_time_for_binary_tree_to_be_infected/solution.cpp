// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Same as 'Distance K' problem. Map parents. Find the start node. Perform BFS from start node. The time taken is the number of levels in BFS until all reachable nodes are visited.

TreeNode* markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m, int start) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res;
    while(!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if(node->val == start) res = node;
        if(node->left) {
            m[node->left] = node;
            q.push(node->left);
        }
        if(node->right) {
            m[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}
int amountOfTime(TreeNode* root, int start) {
    unordered_map<TreeNode*, TreeNode*> m;
    TreeNode* target = markParents(root, m, start);
    unordered_map<TreeNode*, int> vis;
    queue<TreeNode*> q;
    q.push(target);
    vis[target] = 1;
    int maxi = 0;
    while(!q.empty()) {
        int sz = q.size();
        int fl = 0;
        for(int i=0; i<sz; i++) {
            auto node = q.front(); q.pop();
            if(node->left && !vis[node->left]) {
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if(node->right && !vis[node->right]) {
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if(m[node] && !vis[m[node]]) {
                fl = 1;
                vis[m[node]] = 1;
                q.push(m[node]);
            }
        }
        if(fl) maxi++;
    }
    return maxi;
}


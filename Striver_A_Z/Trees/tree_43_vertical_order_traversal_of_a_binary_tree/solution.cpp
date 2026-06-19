// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Use BFS to traverse the tree. Store coordinates `(x, y)` along with nodes in a queue. Use a nested map `map<int, map<int, multiset<int>>> nodes` to store nodes grouped by `x` (vertical level), then by `y` (horizontal level). `multiset` handles sorting when multiple nodes share the same coordinates.

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> q;
    if(root) q.push({root, {0, 0}});
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->val);
        if(node->left) q.push({node->left, {x - 1, y + 1}});
        if(node->right) q.push({node->right, {x + 1, y + 1}});
    }
    vector<vector<int>> ans;
    for(auto p : nodes) {
        vector<int> col;
        for(auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}


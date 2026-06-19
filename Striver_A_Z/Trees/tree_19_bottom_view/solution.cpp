// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: BFS traversal maintaining horizontal distance (HD). Map `hd -> value`. Always update the map value for a given HD so that the last node encountered (bottom-most) overrides previous ones.

vector<int> bottomView(Node *root) {
    vector<int> ans;
    if(root == NULL) return ans;
    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        auto it = q.front(); q.pop();
        Node* node = it.first;
        int line = it.second;
        mpp[line] = node->data;
        if(node->left != NULL) q.push({node->left, line - 1});
        if(node->right != NULL) q.push({node->right, line + 1});
    }
    for(auto it : mpp) ans.push_back(it.second);
    return ans;
}


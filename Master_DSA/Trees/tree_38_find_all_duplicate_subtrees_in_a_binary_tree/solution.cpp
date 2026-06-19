// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: Serialize each subtree into a string (e.g., using preorder traversal). Use a hash map to count the frequencies of these serialized strings. If a string appears exactly twice, add the root of that subtree to the result list.

string solve(Node* root, unordered_map<string, int>& m, vector<Node*>& ans) {
    if(!root) return "N";
    string s = to_string(root->data) + "," + solve(root->left, m, ans) + "," + solve(root->right, m, ans);
    m[s]++;
    if(m[s] == 2) ans.push_back(root);
    return s;
}
vector<Node*> printAllDups(Node* root) {
    unordered_map<string, int> m;
    vector<Node*> ans;
    solve(root, m, ans);
    return ans;
}


// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Serialize each subtree into a string. Use a hash map to store the frequencies of the serialized strings. If any string (of length > 3 to ignore leaves) has a frequency > 1, a duplicate subtree exists.

string solve(Node* root, unordered_map<string, int>& m) {
    if(!root) return "$";
    string s = "";
    if(!root->left && !root->right) {
        s += to_string(root->data);
        return s;
    }
    s = s + to_string(root->data) + "-" + solve(root->left, m) + "-" + solve(root->right, m);
    m[s]++;
    return s;
}
int dupSub(Node *root) {
    unordered_map<string, int> m;
    solve(root, m);
    for(auto it : m) {
        if(it.second >= 2) return 1;
    }
    return 0;
}


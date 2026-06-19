// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a helper function that takes the string and an index pointer. Extract the number. Then if there's a '(' build left tree, and if there's another '(' build right tree.

Node* treeFromStringHelper(string& s, int& i) {
    if(i >= s.length()) return NULL;
    int num = 0, sign = 1;
    if(s[i] == '-') { sign = -1; i++; }
    while(i < s.length() && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    Node* root = new Node(num * sign);
    if(i < s.length() && s[i] == '(') {
        i++;
        root->left = treeFromStringHelper(s, i);
        i++; // skip ')'
    }
    if(i < s.length() && s[i] == '(') {
        i++;
        root->right = treeFromStringHelper(s, i);
        i++; // skip ')'
    }
    return root;
}
Node *treeFromString(string s) {
    int i = 0;
    return treeFromStringHelper(s, i);
}


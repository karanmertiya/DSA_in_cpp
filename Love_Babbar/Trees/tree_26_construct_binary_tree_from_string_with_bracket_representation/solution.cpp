// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a recursive function. Read the number (handling negatives and multi-digits) to create the node. If the next character is `(`, make a recursive call for the left child. If there's another `(`, make a recursive call for the right child. Return the node.

Node* constructTree(string s, int& i) {
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
        root->left = constructTree(s, i);
        i++;
    }
    if(i < s.length() && s[i] == '(') {
        i++;
        root->right = constructTree(s, i);
        i++;
    }
    return root;
}
Node* treeFromString(string str) {
    int i = 0;
    return constructTree(str, i);
}


// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Iterate through string. If digit or sign, parse number and create node. If '(', continue. If node created, push to stack. If ')', pop from stack. If it has a parent, attach it (left first, then right).

TreeNode* treeFromString(string s) {
    if(s.empty()) return NULL;
    stack<TreeNode*> st;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ')') {
            st.pop();
        } else if(s[i] >= '0' && s[i] <= '9' || s[i] == '-') {
            int j = i;
            while(j < s.length() && (s[j] >= '0' && s[j] <= '9' || s[j] == '-')) j++;
            int num = stoi(s.substr(i, j - i));
            TreeNode* node = new TreeNode(num);
            if(!st.empty()) {
                TreeNode* parent = st.top();
                if(!parent->left) parent->left = node;
                else parent->right = node;
            }
            st.push(node);
            i = j - 1;
        }
    }
    while(st.size() > 1) st.pop();
    return st.top();
}


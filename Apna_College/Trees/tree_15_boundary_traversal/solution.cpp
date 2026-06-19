// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: 1) Add root if not leaf. 2) Traverse left boundary (excluding leaves). 3) Inorder traverse all leaves. 4) Traverse right boundary, reverse it, then add to answer.

bool isLeaf(TreeNode* root) { return !root->left && !root->right; }
void addLeft(TreeNode* root, vector<int>& res) {
    TreeNode* cur = root->left;
    while(cur) {
        if(!isLeaf(cur)) res.push_back(cur->val);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}
void addRight(TreeNode* root, vector<int>& res) {
    TreeNode* cur = root->right;
    vector<int> tmp;
    while(cur) {
        if(!isLeaf(cur)) tmp.push_back(cur->val);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for(int i = tmp.size()-1; i>=0; --i) res.push_back(tmp[i]);
}
void addLeaves(TreeNode* root, vector<int>& res) {
    if(isLeaf(root)) { res.push_back(root->val); return; }
    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}
vector<int> boundary(TreeNode *root) {
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->val);
    addLeft(root, res); addLeaves(root, res); addRight(root, res);
    return res;
}


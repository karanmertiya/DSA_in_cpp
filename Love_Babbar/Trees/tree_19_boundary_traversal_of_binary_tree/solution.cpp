// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: 1. If root is not leaf, add root. 2. Get left boundary (excluding leaves). 3. Get all leaves. 4. Get right boundary (excluding leaves) and reverse it.

bool isLeaf(Node* root) {
    return !root->left && !root->right;
}
void addLeftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while(curr) {
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}
void addLeaves(Node* root, vector<int>& res) {
    if(isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}
void addRightBoundary(Node* root, vector<int>& res) {
    Node* curr = root->right;
    vector<int> temp;
    while(curr) {
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i = temp.size() - 1; i >= 0; --i) res.push_back(temp[i]);
}
vector <int> boundary(Node *root) {
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}


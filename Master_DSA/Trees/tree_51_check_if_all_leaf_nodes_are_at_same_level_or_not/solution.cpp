// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Traverse the tree, maintaining the current level. The first time a leaf is encountered, store its level. For subsequent leaves, compare their level with the stored level. If any mismatch occurs, return false.

bool checkUtil(Node* root, int level, int& leafLevel) {
    if(!root) return true;
    if(!root->left && !root->right) {
        if(leafLevel == 0) {
            leafLevel = level;
            return true;
        }
        return (level == leafLevel);
    }
    return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel);
}
bool check(Node *root) {
    int leafLevel = 0;
    return checkUtil(root, 1, leafLevel);
}


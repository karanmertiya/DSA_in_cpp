// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Use a recursive function. A leaf node is always a SumTree. For an internal node, calculate the sum of its left and right subtrees. If its value equals the sum, and both subtrees are SumTrees, return true.

pair<bool, int> isSumTreeFast(Node* root) {
    if(!root) return {true, 0};
    if(!root->left && !root->right) return {true, root->data};
    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);
    bool isSum = (root->data == leftAns.second + rightAns.second);
    if(leftAns.first && rightAns.first && isSum) {
        return {true, 2 * root->data};
    } else {
        return {false, 0};
    }
}
bool isSumTree(Node* root) {
    return isSumTreeFast(root).first;
}


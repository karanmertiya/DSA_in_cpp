// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Use a recursive function. If the target node is found, return it. As you return back up the call stack, decrement `k`. When `k` becomes 0, the current node is the kth ancestor.

Node* solve(Node* root, int& k, int node) {
    if(!root) return NULL;
    if(root->data == node) return root;
    Node* left = solve(root->left, k, node);
    Node* right = solve(root->right, k, node);
    if(left || right) {
        k--;
        if(k == 0) {
            k = INT_MAX;
            return root;
        }
        return left ? left : right;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node) {
    Node* ans = solve(root, k, node);
    if(!ans || ans->data == node) return -1;
    return ans->data;
}


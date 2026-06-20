// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: 1. Find LCA of the two nodes. 2. Find distance from LCA to node 1. 3. Find distance from LCA to node 2. 4. Return the sum.

Node* lca(Node* root, int a, int b) {
    if(!root || root->data == a || root->data == b) return root;
    Node* left = lca(root->left, a, b);
    Node* right = lca(root->right, a, b);
    if(!left) return right;
    if(!right) return left;
    return root;
}
int findDist(Node* root, int val, int dist) {
    if(!root) return -1;
    if(root->data == val) return dist;
    int d = findDist(root->left, val, dist + 1);
    if(d != -1) return d;
    return findDist(root->right, val, dist + 1);
}
int findDist(Node* root, int a, int b) {
    Node* lca_node = lca(root, a, b);
    int d1 = findDist(lca_node, a, 0);
    int d2 = findDist(lca_node, b, 0);
    return d1 + d2;
}


// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Find the Lowest Common Ancestor (LCA) of the two nodes. Then find the distance from LCA to the first node and the distance from LCA to the second node. The total distance is the sum of these two distances.

Node* lca(Node* root, int n1, int n2) {
    if(!root || root->data == n1 || root->data == n2) return root;
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);
    if(left && right) return root;
    return left ? left : right;
}
int findDist(Node* root, int val, int dist) {
    if(!root) return -1;
    if(root->data == val) return dist;
    int left = findDist(root->left, val, dist + 1);
    if(left != -1) return left;
    return findDist(root->right, val, dist + 1);
}
int findDist(Node* root, int a, int b) {
    Node* lca_node = lca(root, a, b);
    return findDist(lca_node, a, 0) + findDist(lca_node, b, 0);
}


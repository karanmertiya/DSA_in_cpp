// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Kth largest is Kth element in reverse inorder traversal (Right, Root, Left). Maintain a counter `k`. When visiting a node, decrement `k`. If `k == 0`, current node is the answer.

int ans = -1;
void reverseInorder(Node* root, int& k) {
    if(!root || k == 0) return;
    reverseInorder(root->right, k);
    k--;
    if(k == 0) {
        ans = root->data;
        return;
    }
    reverseInorder(root->left, k);
}
int kthLargest(Node *root, int K) {
    ans = -1;
    reverseInorder(root, K);
    return ans;
}


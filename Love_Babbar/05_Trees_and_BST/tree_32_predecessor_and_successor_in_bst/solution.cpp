// Time Complexity: O(H)
// Space Complexity: O(1)
// Explanation: For Successor: search for key. If node->val <= key, go right. If node->val > key, update succ = node, go left. For Predecessor: If node->val >= key, go left. If node->val < key, update pred = node, go right.

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    Node* curr = root;
    while(curr) {
        if(curr->key > key) {
            suc = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    curr = root;
    while(curr) {
        if(curr->key < key) {
            pre = curr;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
}


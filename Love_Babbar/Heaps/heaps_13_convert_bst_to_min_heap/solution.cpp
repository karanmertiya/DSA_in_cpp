// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Since a BST inorder gives sorted values, store the inorder traversal in an array. The requirement says left subtree elements < right subtree elements, which matches a Preorder traversal (Root, Left, Right) since we want the smallest element at the root. So do a Preorder traversal of the tree and replace nodes with array elements.

void inorder(Node* root, vector<int>& arr) {
    if(!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
void preorderFill(Node* root, vector<int>& arr, int& i) {
    if(!root) return;
    root->data = arr[i++];
    preorderFill(root->left, arr, i);
    preorderFill(root->right, arr, i);
}
void convertToMinHeapUtil(Node* root) {
    vector<int> arr;
    inorder(root, arr);
    int i = 0;
    preorderFill(root, arr, i);
}


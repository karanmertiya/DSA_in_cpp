// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Use recursion. Push current node to the path array. If it's the target node, return true. Recursively search left and right subtrees. If either returns true, return true. If not found in either, pop the current node from the path array and return false.

bool getPath(TreeNode* root, vector<int>& arr, int x) {
    if(!root) return false;
    arr.push_back(root->val);
    if(root->val == x) return true;
    if(getPath(root->left, arr, x) || getPath(root->right, arr, x)) return true;
    arr.pop_back();
    return false;
}
vector<int> solve(TreeNode* A, int B) {
    vector<int> arr;
    if(!A) return arr;
    getPath(A, arr, B);
    return arr;
}


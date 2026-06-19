// Time Complexity: O(N)
// Space Complexity: O(H)
// Explanation: Use DFS. Keep track of the maximum length and the maximum sum. At each node, check if the current length is greater than max length. If so, update max length and max sum. If lengths are equal, update max sum if current sum is greater.

void solve(Node* root, int sum, int& maxSum, int len, int& maxLen) {
    if(!root) {
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        } else if(len == maxLen) {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}
int sumOfLongRootToLeafPath(Node *root) {
    int len = 0, maxLen = 0;
    int sum = 0, maxSum = INT_MIN;
    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}


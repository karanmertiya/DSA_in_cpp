// Time Complexity: O(N * W)
// Space Complexity: O(W)
// Explanation: Use a 1D `dp` array of size `W + 1`. For each item, iterate backwards from `W` to `weight[i]`. `dp[w] = max(dp[w], val[i] + dp[w - weight[i]])`.

int knapSack(int W, int wt[], int val[], int n) {
    vector<int> dp(W + 1, 0);
    for(int i = 0; i < n; i++) {
        for(int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}


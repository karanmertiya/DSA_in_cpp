// Time Complexity: O(N * K)
// Space Complexity: O(N)
// Explanation: Let `dp[i]` be the maximum sum for `arr[0..i-1]`. To compute `dp[i]`, iterate back `j` from 1 to `k`. Keep track of the maximum element in `arr[i-j..i-1]`. The sum is `max_val * j + dp[i-j]`. Maximize this over all valid `j`.

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        int curMax = 0, best = 0;
        for(int j = 1; j <= k && i - j >= 0; j++) {
            curMax = max(curMax, arr[i-j]);
            best = max(best, dp[i-j] + curMax * j);
        }
        dp[i] = best;
    }
    return dp[n];
}


// Time Complexity: O(N^3)
// Space Complexity: O(N^2)
// Explanation: Add 1 to both ends of the array. Let `dp[i][j]` be the max coins collected by bursting balloons in `nums[i..j]`. Iterate length `L` from 1 to N. For each window `[i, j]`, try every `k` from `i` to `j` as the LAST balloon to burst in this window. Cost is `nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j]`.

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    vector<int> arr(n + 2, 1);
    for(int i = 0; i < n; i++) arr[i+1] = nums[i];
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for(int L = 1; L <= n; L++) {
        for(int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            for(int k = i; k <= j; k++) {
                int cost = arr[i-1] * arr[k] * arr[j+1] + dp[i][k-1] + dp[k+1][j];
                dp[i][j] = max(dp[i][j], cost);
            }
        }
    }
    return dp[1][n];
}


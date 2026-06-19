// Time Complexity: O(N^3)
// Space Complexity: O(N^2)
// Explanation: Add 1 to both ends of `nums`. `dp[i][j]` is max coins from bursting balloons strictly between `i` and `j`. Guess which balloon `k` (between `i` and `j`) is the LAST one to burst. Coins gained = `nums[i] * nums[k] * nums[j]`. Total = `dp[i][k] + dp[k][j] + coins`.

int maxCoins(vector<int>& nums) {
    vector<int> a = {1};
    for(int num : nums) a.push_back(num);
    a.push_back(1);
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int len = 2; len < n; len++) {
        for(int i = 0; i < n - len; i++) {
            int j = i + len;
            for(int k = i + 1; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
            }
        }
    }
    return dp[0][n-1];
}


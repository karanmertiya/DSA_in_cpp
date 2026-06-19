// Time Complexity: O(C^3) where C is number of cuts
// Space Complexity: O(C^2)
// Explanation: Add 0 and `n` to `cuts`, then sort. `dp[i][j]` is min cost to cut the sub-stick between `cuts[i]` and `cuts[j]`. Try all possible cuts `k` between `i` and `j`. `dp[i][j] = min(dp[i][k] + dp[k][j]) + cuts[j] - cuts[i]`.

int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    int c = cuts.size();
    vector<vector<int>> dp(c, vector<int>(c, 0));
    for(int len = 2; len < c; len++) {
        for(int i = 0; i < c - len; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for(int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
            }
        }
    }
    return dp[0][c-1];
}


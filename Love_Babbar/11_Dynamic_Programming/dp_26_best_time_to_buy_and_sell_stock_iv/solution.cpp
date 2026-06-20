// Time Complexity: O(N * K)
// Space Complexity: O(N * K) or O(K)
// Explanation: If `k >= n/2`, it's equivalent to infinite transactions (Stock II). Else, use a DP array `dp[k][n]` where `dp[i][j]` is max profit using `i` transactions up to day `j`. Optimize inner loop by tracking `maxDiff = max(maxDiff, dp[i-1][j-1] - prices[j-1])`.

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if(n <= 1) return 0;
    if(k >= n / 2) {
        int profit = 0;
        for(int i = 1; i < n; i++) {
            if(prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
        }
        return profit;
    }
    vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
    for(int price : prices) {
        for(int i = 1; i <= k; i++) {
            buy[i] = max(buy[i], sell[i-1] - price);
            sell[i] = max(sell[i], buy[i] + price);
        }
    }
    return sell[k];
}


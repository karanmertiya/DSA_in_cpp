// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Add the profit whenever the price is higher than the previous day. This is equivalent to capturing every upward slope.

int maxProfit(vector<int>& prices) {
    int profit = 0;
    for(int i = 1; i < prices.size(); i++) {
        if(prices[i] > prices[i-1]) {
            profit += prices[i] - prices[i-1];
        }
    }
    return profit;
}


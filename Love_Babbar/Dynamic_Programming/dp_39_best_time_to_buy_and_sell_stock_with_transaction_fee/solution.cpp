// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Similar to Stock II, but subtract `fee` when selling. Maintain `cash` (max profit not holding stock) and `hold` (max profit holding stock). `cash = max(cash, hold + price - fee)`, `hold = max(hold, cash - price)`.

int maxProfit(vector<int>& prices, int fee) {
    int cash = 0, hold = -prices[0];
    for(int i = 1; i < prices.size(); i++) {
        cash = max(cash, hold + prices[i] - fee);
        hold = max(hold, cash - prices[i]);
    }
    return cash;
}


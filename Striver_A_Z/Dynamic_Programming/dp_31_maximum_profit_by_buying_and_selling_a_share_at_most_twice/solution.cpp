// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Track 4 states: `buy1`, `sell1`, `buy2`, `sell2`. Initialize buys to negative infinity, sells to 0. Update them for each price. `buy1 = max(buy1, -price)`, `sell1 = max(sell1, buy1 + price)`, `buy2 = max(buy2, sell1 - price)`, `sell2 = max(sell2, buy2 + price)`.

int maxProfit(vector<int>& prices) {
    int buy1 = INT_MIN, sell1 = 0;
    int buy2 = INT_MIN, sell2 = 0;
    for(int price : prices) {
        buy1 = max(buy1, -price);
        sell1 = max(sell1, buy1 + price);
        buy2 = max(buy2, sell1 - price);
        sell2 = max(sell2, buy2 + price);
    }
    return sell2;
}


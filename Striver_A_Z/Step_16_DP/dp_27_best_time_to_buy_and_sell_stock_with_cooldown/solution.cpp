// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Maintain 3 states: `hold` (holding a stock), `sold` (just sold, entering cooldown next), `rest` (not holding, not in cooldown). Transitions: `hold = max(hold, rest - price)`, `sold = hold + price`, `rest = max(rest, sold_prev)`.

int maxProfit(vector<int>& prices) {
    int hold = INT_MIN, sold = 0, rest = 0;
    for(int price : prices) {
        int prev_sold = sold;
        sold = hold + price;
        hold = max(hold, rest - price);
        rest = max(rest, prev_sold);
    }
    return max(rest, sold);
}


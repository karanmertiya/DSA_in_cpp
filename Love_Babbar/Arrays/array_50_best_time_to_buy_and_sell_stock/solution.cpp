// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Maintain `min_price` seen so far and calculate potential profit for each day: `prices[i] - min_price`. Update `max_profit` if this profit is greater.

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProf = 0;
    for(int p : prices) {
        minPrice = min(minPrice, p);
        maxProf = max(maxProf, p - minPrice);
    }
    return maxProf;
}


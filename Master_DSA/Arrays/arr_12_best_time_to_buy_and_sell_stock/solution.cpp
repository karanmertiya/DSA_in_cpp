// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    int min_price = prices[0];
    int max_profit = 0;
    for(int i = 1; i < prices.size(); i++) {
        max_profit = std::max(max_profit, prices[i] - min_price);
        min_price = std::min(min_price, prices[i]);
    }
    return max_profit;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1)
// Explanation: Optimal: Iterate while keeping track of the minimum price seen so far. Subtract this min from the current price to find potential profit.

#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    int min_price = prices[0];
    int max_profit = 0;
    for(int i = 1; i < prices.size(); i++) {
        max_profit = std::max(max_profit, prices[i] - min_price);
        min_price = std::min(min_price, prices[i]);
    }
    return max_profit;
}


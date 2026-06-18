// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) + O(N) Recursion Stack
// Explanation: Memoization (Top-Down): Recursive tree caching already solved subproblems in an array.

#include <vector>

int solve(int n, std::vector<int>& dp) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int climbStairsMemo(int n) {
    std::vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

// Time Complexity: O(N)
// Space Complexity: O(1) (Constraint)
// Explanation: Space Optimization (Bottom-Up): Since state `n` only depends on `n-1` and `n-2`, we only need two variables.

int climbStairsOptimal(int n) {
    if (n <= 1) return 1;
    int prev2 = 1;
    int prev = 1;
    for(int i = 2; i <= n; i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}


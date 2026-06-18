// Time Complexity: O(N)
// Space Complexity: O(1) (Constraint)
// Explanation: Space Optimization (Bottom-Up): Since state `n` only depends on `n-1` and `n-2`, we only need two variables.

int climbStairs(int n) {
    if (n <= 1) return 1;
    int prev2 = 1, prev = 1;
    for(int i = 2; i <= n; i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}


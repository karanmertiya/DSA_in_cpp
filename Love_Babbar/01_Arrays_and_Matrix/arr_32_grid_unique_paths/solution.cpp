// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int uniquePaths(int m, int n) {
    int N = n + m - 2;
    int r = m - 1;
    double res = 1;
    for(int i = 1; i <= r; i++) {
        res = res * (N - r + i) / i;
    }
    return (int)res;
}

// Time Complexity: O(m-1)
// Space Complexity: O(1)
// Explanation: Optimal: Combinatorics approach. The total number of steps to reach the bottom-right corner is (m - 1) + (n - 1) = m + n - 2. Out of these steps, we need to choose (m - 1) downward steps (or n - 1 rightward steps). The number of paths is (m + n - 2) C (m - 1).

int uniquePaths(int m, int n) {
    int N = n + m - 2;
    int r = m - 1;
    double res = 1;
    for(int i = 1; i <= r; i++) {
        res = res * (N - r + i) / i;
    }
    return (int)res;
}


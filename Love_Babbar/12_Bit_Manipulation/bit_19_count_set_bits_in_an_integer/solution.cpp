// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: Use Brian Kernighan's algorithm: `n = n & (n - 1)` unsets the rightmost set bit. Keep doing this until `n` becomes 0 and count the operations.

int setBits(int N) {
    int count = 0;
    while(N > 0) {
        N = N & (N - 1);
        count++;
    }
    return count;
}


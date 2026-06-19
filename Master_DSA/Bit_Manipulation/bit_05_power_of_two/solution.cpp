// Time Complexity: O(log2(N)) (Trade-off)
// Space Complexity: O(1)
// Explanation: Iteratively divide by 2. If it ever yields an odd number > 1, it is not a power of 2.

bool isPowerOfTwoBrute(int n) {
    if (n <= 0) return false;
    while(n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}


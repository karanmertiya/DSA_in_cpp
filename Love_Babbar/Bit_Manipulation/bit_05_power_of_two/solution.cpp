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

// Time Complexity: O(1) (Constraint)
// Space Complexity: O(1)
// Explanation: A power of 2 has exactly 1 set bit. Thus `N & (N-1)` must equal 0.

bool isPowerOfTwoOptimal(int n) {
    // Edge Case: N > 0 handles both 0 and negative inputs inherently
    return (n > 0) && ((n & (n - 1)) == 0);
}


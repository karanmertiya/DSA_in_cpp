// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: If a number is a power of two, it has exactly one bit set in its binary representation. The expression `n & (n - 1)` clears the lowest set bit. Thus, if `n > 0` and `(n & (n - 1)) == 0`, it is a power of two.

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}


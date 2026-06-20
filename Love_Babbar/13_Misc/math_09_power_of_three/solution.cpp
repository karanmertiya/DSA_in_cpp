// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Since `n` is a 32-bit signed integer, the largest power of 3 that fits is `3^19 = 1162261467`. A number `n` is a power of 3 if `n > 0` and `1162261467 % n == 0`.

bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
}


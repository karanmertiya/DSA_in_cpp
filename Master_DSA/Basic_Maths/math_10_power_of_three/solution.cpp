// Time Complexity: O(log_3 N)
// Space Complexity: O(1)
// Explanation: General Method: Repeatedly divide the number by 3 as long as it is divisible by 3. If it becomes 1, it's a power of 3.

bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    while (n % 3 == 0) n /= 3;
    return n == 1;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Since `n` is a 32-bit signed integer, the largest power of 3 that fits is `3^19 = 1162261467`. A number `n` is a power of 3 if `n > 0` and `1162261467 % n == 0`.

bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
}


// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Right shift N by i times and check if the least significant bit is 1.

bool checkKthBitRightShift(int n, int k) {
    return ((n >> k) & 1) != 0;
}

// Time Complexity: O(1) (Constraint)
// Space Complexity: O(1)
// Explanation: Left shift 1 by i times to create a mask, then bitwise AND with N.

bool checkKthBitLeftShift(int n, int k) {
    // Edge Case: 1LL prevents overflow if k >= 31
    return (n & (1LL << k)) != 0;
}


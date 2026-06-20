// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Right shift N by K times and check if the least significant bit is 1.

bool checkKthBitRightShift(int n, int k) {
    return ((n >> k) & 1) != 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Create a mask by left shifting 1 by K times and check if the bitwise AND with N is non-zero.

bool checkKthBit(int n, int k) {
    return (n & (1LL << k)) != 0;
}


// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Right shift N by i times and check if the least significant bit is 1.

bool checkKthBitRightShift(int n, int k) {
    return ((n >> k) & 1) != 0;
}


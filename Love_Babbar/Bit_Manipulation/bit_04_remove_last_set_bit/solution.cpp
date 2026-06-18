// Time Complexity: O(1) (Constraint)
// Space Complexity: O(1)
// Explanation: Bitwise AND between N and N-1 naturally flips the lowest set bit to 0.

int removeLastSetBit(int n) {
    // Edge Case check for zero underflow
    if (n <= 0) return 0;
    return n & (n - 1);
}


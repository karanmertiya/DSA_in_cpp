// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Use basic arithmetic (addition and subtraction) to swap.

void swapArithmetic(int &a, int &b) {
    // Edge Case: Can overflow for massive 32-bit integers
    a = a + b;
    b = a - b;
    a = a - b;
}


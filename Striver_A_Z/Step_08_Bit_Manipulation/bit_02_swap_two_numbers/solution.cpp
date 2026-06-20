// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Use basic arithmetic (addition and subtraction) to swap.

void swapArithmetic(int &a, int &b) {
    // Edge Case: Can overflow for massive 32-bit integers
    a = a + b;
    b = a - b;
    a = a - b;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Use XOR bitwise operation. XORing a number with itself is 0, and XORing with 0 is the number itself.

vector<int> get(int a, int b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return {a, b};
}


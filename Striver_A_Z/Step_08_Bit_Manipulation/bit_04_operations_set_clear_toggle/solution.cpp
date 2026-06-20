// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Use OR (`|`) to set, AND with NOT (`& ~`) to clear, and XOR (`^`) to toggle.

vector<int> bitOperations(int n, int i) {
    int setBit = n | (1LL << i);
    int clearBit = n & ~(1LL << i);
    int toggleBit = n ^ (1LL << i);
    return {setBit, clearBit, toggleBit};
}


// Time Complexity: O(1) (Constraint)
// Space Complexity: O(1)
// Explanation: Use OR (`|`) to set, AND with NOT (`& ~`) to clear, and XOR (`^`) to toggle.

#include <vector>
#include <iostream>

std::vector<long long> bitOperations(long long n, int i) {
    long long setBit = n | (1LL << i);
    long long clearBit = n & ~(1LL << i);
    long long toggleBit = n ^ (1LL << i);
    return {setBit, clearBit, toggleBit};
}


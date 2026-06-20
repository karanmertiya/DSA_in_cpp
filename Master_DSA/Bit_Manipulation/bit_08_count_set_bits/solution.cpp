// Time Complexity: O(32) &cong; O(1)
// Space Complexity: O(1)
// Explanation: Iterate through all 32 bits and check if each is set by right shifting N and checking the 0th bit.

int hammingWeightLoop(uint32_t n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

// Time Complexity: O(Set Bits)
// Space Complexity: O(1)
// Explanation: Use Brian Kernighan's algorithm: `n = n & (n - 1)` unsets the rightmost set bit. Keep doing this until `n` becomes 0.

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}


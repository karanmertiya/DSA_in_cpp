// Time Complexity: O(32) &cong; O(1) (Trade-off)
// Space Complexity: O(1)
// Explanation: Iterate through all 32 bits and check if each is set.

int hammingWeightBrute(uint32_t n) {
    int count = 0;
    for(int i=0; i<32; i++) {
        if((n >> i) & 1) {
            count++;
        }
    }
    return count;
}

// Time Complexity: O(Set Bits) (Constraint)
// Space Complexity: O(1)
// Explanation: Brian Kernighan's Algorithm: Strip the lowest set bit using `N & (N-1)` until N reaches 0.

int hammingWeightOptimal(uint32_t n) {
    int count = 0;
    while (n != 0) {
        // Strips the rightmost set bit dynamically
        n = n & (n - 1);
        count++;
    }
    return count;
}


// Time Complexity: O(Set Bits)
// Space Complexity: O(1)
// Explanation: XOR `start` and `goal` to isolate differing bits, then count the set bits in the result.

int minBitFlips(int start, int goal) {
    int xor_res = start ^ goal;
    int count = 0;
    // Brian Kernighan's algorithm to count the mismatched bits
    while(xor_res != 0) {
        xor_res = xor_res & (xor_res - 1);
        count++;
    }
    return count;
}


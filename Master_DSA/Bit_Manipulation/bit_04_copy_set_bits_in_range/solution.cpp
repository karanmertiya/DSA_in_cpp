// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Create a mask of length (R - L + 1) with all 1s. Shift this mask to the left by (L - 1). AND this mask with Y to isolate the bits to be copied. Finally, OR this isolated value with X.

int setSetBit(int x, int y, int l, int r){
    int mask = (1 << (r - l + 1)) - 1;
    mask = (mask << (l - 1));
    mask = mask & y;
    return x | mask;
}


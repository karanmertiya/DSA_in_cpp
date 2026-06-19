// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Create a mask of length `r - l + 1` with all 1s. Shift this mask left by `l - 1`. Apply this mask to `y` using AND (`y & mask`). Finally, OR the result with `x`.

int setSetBit(int x, int y, int l, int r){
    int maskLen = r - l + 1;
    int mask = ((1 << maskLen) - 1) << (l - 1);
    int yMasked = y & mask;
    return x | yMasked;
}


// Time Complexity: O(32)
// Space Complexity: O(1)
// Explanation: Loop through all 32 bits, count set bits, and record the position. If count is strictly 1, return position, else -1.

int findPositionBrute(int N) {
    int count = 0, pos = -1, curr = 1;
    while(N > 0) {
        if(N & 1) {
            count++;
            pos = curr;
        }
        N >>= 1;
        curr++;
    }
    return count == 1 ? pos : -1;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: First, check if `N` is a power of 2 using `N & (N - 1) == 0`. If yes, the position is `log2(N) + 1`.

int findPosition(int N) {
    if(N == 0 || (N & (N - 1)) != 0) return -1;
    return log2(N) + 1;
}


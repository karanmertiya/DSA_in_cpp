// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Check if the number is a power of 2 using `(N & (N - 1)) == 0`. If yes, the position is `log2(N) + 1`.

int findPosition(int N) {
    if(N == 0 || (N & (N - 1)) != 0) return -1;
    return log2(N) + 1;
}


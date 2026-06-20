// Time Complexity: O(log N)
// Space Complexity: O(log N)
// Explanation: If `n` is even, `n = 2*x`, then `n^2 = 4*x^2 = (x^2) << 2`. If `n` is odd, `n = 2*x + 1`, then `n^2 = 4*x^2 + 4*x + 1 = ((x^2 + x) << 2) + 1`.

int square(int n) {
    if(n == 0) return 0;
    if(n < 0) n = -n;
    int x = n >> 1;
    if(n & 1) return ((square(x) << 2) + (x << 2) + 1);
    else return (square(x) << 2);
}


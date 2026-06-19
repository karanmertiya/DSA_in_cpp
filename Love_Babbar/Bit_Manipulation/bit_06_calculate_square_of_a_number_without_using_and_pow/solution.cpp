// Time Complexity: O(log N)
// Space Complexity: O(log N) recursion stack
// Explanation: Use `n^2 = (2x)^2 = 4x^2` if n is even (n = 2x). If n is odd (n = 2x+1), `n^2 = (2x+1)^2 = 4x^2 + 4x + 1`. This allows calculating the square using bitwise shifts (multiply by 4 is `<< 2`, multiply by 2 is `<< 1`).

int square(int n) {
    if(n == 0) return 0;
    if(n < 0) n = -n;
    int x = n >> 1;
    if(n & 1) return ((square(x) << 2) + (x << 2) + 1);
    else return (square(x) << 2);
}


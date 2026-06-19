// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: Keep shifting `divisor` left by `i` bits until it's just smaller than `dividend`. Subtract `divisor << i` from `dividend` and add `1 << i` to the `quotient`. Repeat.

int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    long long a = abs((long long)dividend);
    long long b = abs((long long)divisor);
    int res = 0;
    while(a - b >= 0) {
        int x = 0;
        while(a - (b << 1 << x) >= 0) x++;
        res += 1 << x;
        a -= b << x;
    }
    return (dividend > 0) == (divisor > 0) ? res : -res;
}


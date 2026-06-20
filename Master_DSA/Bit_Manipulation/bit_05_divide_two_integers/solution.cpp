// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Iterative subtraction. Subtract divisor from dividend until dividend is smaller than divisor. Count the number of subtractions.

int divideBrute(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    long long a = abs((long long)dividend);
    long long b = abs((long long)divisor);
    int res = 0;
    while(a >= b) {
        a -= b;
        res++;
    }
    return (dividend > 0) == (divisor > 0) ? res : -res;
}

// Time Complexity: O(log^2 N)
// Space Complexity: O(1)
// Explanation: Use left shift to find the largest multiple of divisor that fits into dividend. Subtract it and add the shifted value to quotient. Repeat until dividend < divisor.

int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    long long n = abs(dividend), d = abs(divisor), quotient = 0;
    bool sign = (dividend < 0) == (divisor < 0);
    while(n >= d) {
        long long temp = d, multiple = 1;
        while(n >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        n -= temp;
        quotient += multiple;
    }
    return sign ? quotient : -quotient;
}


// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: Determine the sign. Work with absolute values. Keep shifting the divisor left (multiplying by 2) until it's greater than the dividend. The shift amount `i` means the divisor can be multiplied by `2^i`. Subtract `(divisor << i)` from dividend, add `2^i` to quotient. Repeat until dividend < divisor.

long long divide(long long dividend, long long divisor) {
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    dividend = abs(dividend);
    divisor = abs(divisor);
    long long quotient = 0, temp = 0;
    for(int i = 31; i >= 0; i--) {
        if(temp + (divisor << i) <= dividend) {
            temp += divisor << i;
            quotient |= 1LL << i;
        }
    }
    return sign * quotient;
}


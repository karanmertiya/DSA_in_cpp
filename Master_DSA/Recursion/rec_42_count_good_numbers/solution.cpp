// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: There are 5 even digits and 4 prime digits. At even indices we have 5 choices. At odd indices we have 4 choices. If `n` is even, we have `n/2` even indices and `n/2` odd indices. So answer is `(5^(n/2) * 4^(n/2)) % mod`. If `n` is odd, we have `n/2 + 1` even indices. So answer is `(5^(n/2 + 1) * 4^(n/2)) % mod`. Use binary exponentiation.

long long power(long long x, long long y) {
    long long res = 1;
    long long mod = 1e9 + 7;
    x = x % mod;
    while(y > 0) {
        if(y % 2 == 1) res = (res * x) % mod;
        y = y / 2;
        x = (x * x) % mod;
    }
    return res;
}
int countGoodNumbers(long long n) {
    long long mod = 1e9 + 7;
    long long evenIndices = (n + 1) / 2;
    long long oddIndices = n / 2;
    return (power(5, evenIndices) * power(4, oddIndices)) % mod;
}


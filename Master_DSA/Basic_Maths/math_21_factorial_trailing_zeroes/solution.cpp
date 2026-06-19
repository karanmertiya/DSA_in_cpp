// Time Complexity: O(log5(N))
// Space Complexity: O(1)
// Explanation: Trailing zeroes are produced by the prime factors 2 and 5. Since 2 is always more abundant than 5, we just need to count the number of 5s in the prime factorization of `n!`. This is done by repeatedly dividing `n` by 5 and adding the quotients.

int trailingZeroes(int n) {
    int count = 0;
    while(n > 0) {
        count += n / 5;
        n /= 5;
    }
    return count;
}


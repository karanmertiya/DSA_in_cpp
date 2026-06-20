// Time Complexity: O(log_5(N))
// Space Complexity: O(1)
// Explanation: Trailing zeroes are produced by 10s, which are pairs of 2 and 5. Since 2s are more frequent, we just count the number of 5s in prime factors of numbers up to N. This is `N/5 + N/25 + N/125 + ...`.

int trailingZeroes(int n) {
    int count = 0;
    while(n > 0) {
        count += n / 5;
        n /= 5;
    }
    return count;
}


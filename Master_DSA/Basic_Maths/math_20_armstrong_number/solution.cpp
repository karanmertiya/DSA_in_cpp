// Time Complexity: O(log10(N))
// Space Complexity: O(1)
// Explanation: Extract each digit, cube it, and sum them up. If the sum equals the original number, it's an Armstrong number.

string armstrongNumber(int n) {
    int original = n, sum = 0;
    while(n > 0) {
        int digit = n % 10;
        sum += (digit * digit * digit);
        n /= 10;
    }
    return sum == original ? "Yes" : "No";
}


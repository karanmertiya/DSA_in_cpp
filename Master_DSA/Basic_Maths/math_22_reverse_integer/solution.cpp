// Time Complexity: O(log10(X))
// Space Complexity: O(1)
// Explanation: Use a while loop to extract the last digit using `x % 10` and add it to the reversed number `ans = ans * 10 + digit`. Check for overflow before multiplying by 10.

int reverse(int x) {
    int ans = 0;
    while(x != 0) {
        int digit = x % 10;
        if(ans > INT_MAX / 10 || ans < INT_MIN / 10) return 0;
        ans = ans * 10 + digit;
        x /= 10;
    }
    return ans;
}


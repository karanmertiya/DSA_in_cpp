// Time Complexity: O(log10 x)
// Space Complexity: O(1)
// Explanation: Strict 32-bit environment (LeetCode standard): Extract digit, check for overflow against INT_MAX/10 and INT_MIN/10 *before* multiplying ans by 10.

int reverse(int x) {
    int ans = 0;
    while(x != 0) {
        int digit = x % 10;
        if(ans > INT_MAX/10 || ans < INT_MIN/10) return 0;
        ans = ans * 10 + digit;
        x /= 10;
    }
    return ans;
}

// Time Complexity: O(log10 x)
// Space Complexity: O(1)
// Explanation: Relaxed 64-bit environment: Store answer in a 64-bit integer (`long long`). At the end, check if it exceeds 32-bit bounds and return 0 if it does.

int reverse(int x) {
    long long ans = 0;
    while(x != 0) {
        int digit = x % 10;
        ans = ans * 10 + digit;
        x /= 10;
    }
    if(ans > INT_MAX || ans < INT_MIN) return 0;
    return ans;
}


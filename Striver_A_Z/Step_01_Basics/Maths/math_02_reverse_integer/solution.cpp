// Time Complexity: O(log10 x)
// Space Complexity: O(1)
// Explanation: Extract last digit using modulo, multiply answer by 10 and add. Check bounds for 32-bit integer.

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


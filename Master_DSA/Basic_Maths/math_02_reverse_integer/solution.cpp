// Time Complexity: O(log10 x)
// Space Complexity: O(1)
// Explanation: Optimal Approach: Use a 64-bit integer to naturally store the reversed number. A variant note explains how to do this strictly with 32-bit integers if long is not allowed.

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

// Time Complexity: O(log10 x)
// Space Complexity: O(log10 x)
// Explanation: Brute Force / String Approach: Convert to string, reverse, and then parse back to integer.

int reverse(int x) {
    string s = to_string(abs(x));
    std::reverse(s.begin(), s.end());
    try {
        long long rev = stoll(s);
        if (x < 0) rev = -rev;
        if (rev > INT_MAX || rev < INT_MIN) return 0;
        return rev;
    } catch (...) {
        return 0;
    }
}


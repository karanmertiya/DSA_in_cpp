// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: 1. Ignore leading whitespaces. 2. Check for optional '+' or '-'. 3. Read digits until a non-digit or end of string. 4. Build the integer, checking for 32-bit integer overflow/underflow at each step.

int myAtoi(string s) {
    int i = 0, n = s.length(), sign = 1;
    long long ans = 0;
    while(i < n && s[i] == ' ') i++;
    if(i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    while(i < n && isdigit(s[i])) {
        ans = ans * 10 + (s[i] - '0');
        if(sign == 1 && ans > INT_MAX) return INT_MAX;
        if(sign == -1 && -ans < INT_MIN) return INT_MIN;
        i++;
    }
    return sign * ans;
}


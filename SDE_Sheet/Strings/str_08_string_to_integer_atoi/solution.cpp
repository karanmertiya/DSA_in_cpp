// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1)
// Explanation: Skip whitespaces, parse sign, and construct integer utilizing math bound checks before applying `x10`.

#include <string>
#include <climits>

int myAtoi(std::string s) {
    int i = 0, n = s.length(), sign = 1, res = 0;
    while(i < n && s[i] == ' ') i++; // Whitespace
    if(i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    while(i < n && s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';
        if(res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        res = res * 10 + digit;
        i++;
    }
    return res * sign;
}


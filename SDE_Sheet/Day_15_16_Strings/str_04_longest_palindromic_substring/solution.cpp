// Time Complexity: O(N<sup>2</sup>) (Constraint)
// Space Complexity: O(1)
// Explanation: Expand Around Center. A palindrome can have an odd (center is 1 char) or even (center is between 2 chars) length. Test both.

#include <string>
#include <algorithm>

int expand(std::string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--; right++;
    }
    return right - left - 1;
}

std::string longestPalindrome(std::string s) {
    if (s.empty()) return "";
    int start = 0, max_len = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expand(s, i, i);
        int len2 = expand(s, i, i + 1);
        int len = std::max(len1, len2);
        if (len > max_len) {
            max_len = len;
            start = i - (len - 1) / 2;
        }
    }
    return s.substr(start, max_len);
}


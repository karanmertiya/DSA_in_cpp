// Time Complexity: O(N<sup>2</sup>) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Expand Around Center: For each character, treat it as the center of an odd and even length palindrome and expand outwards.

#include <string>
#include <algorithm>

std::string longestPalindrome(std::string s) {
    if(s.empty()) return "";
    int start = 0, maxLen = 0;
    auto expand = [&](int l, int r) {
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            if(r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
            l--; r++;
        }
    };
    for(int i = 0; i < s.length(); i++) {
        expand(i, i);     // Odd
        expand(i, i + 1); // Even
    }
    return s.substr(start, maxLen);
}


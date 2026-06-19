// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Explanation: Expand Around Center. A palindrome mirrors around its center. There are 2N-1 centers (each letter, and between each pair of letters). Expand outward as long as it remains a palindrome.

string longestPalindrome(string s) {
    if (s.empty()) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}
int expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--; right++;
    }
    return right - left - 1;
}


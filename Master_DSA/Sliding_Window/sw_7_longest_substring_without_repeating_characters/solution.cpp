// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use a sliding window. Keep expanding the window by adding characters. If a duplicate character is found, shrink the window from the left until the duplicate is removed.

int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int l = 0, r = 0, maxLen = 0;
    while(r < s.length()) {
        if(seen.find(s[r]) == seen.end()) {
            seen.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
            r++;
        } else {
            seen.erase(s[l]);
            l++;
        }
    }
    return maxLen;
}

